/**
 * @file FoodAPI.cpp
 * @author Matthew Cheverie
 * @brief FoodAPI program file. Contains the implementation for FoodAPI class. Used to communicate with Spoonacular API
 * and create various objects
 * Used to represent records in database.
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>
#include <algorithm>
#include "FoodAPI.hpp"
#include "Model.h"
#include <regex>
using namespace std;

const FoodAPI* FoodAPI::_instance = NULL;


/**
 * @brief Returns a single instance of the FoodAPI.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @return Single instance of the FoodAPI object.
 */
const FoodAPI& FoodAPI::getInstance(){
    if(_instance == NULL) {
        _instance = new FoodAPI();
    }
    return *_instance;
}


/**
 * @brief Constructor
 * @author Matthew Cheverie
 * @author Jared Anstett
 */
FoodAPI::FoodAPI(){
    string key = "254ee65b4d89431f9465d6b595199032";
    FoodAPI::setAPIKey(key);    
}


/**
 * @brief Gets the spoonacular API Key
 * @author Matthew Cheverie
 * @author Jared Anstett    
 * @return The API key.
 */
string FoodAPI::getAPIKey() const{
    return this->_apiKey;
}


/**
 * @brief Takes the list of the ingredients in the stock and turns them into a printable string.
 * 
 * @param dbStock The stock of ingredients in the database.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @return The string of all the ingredients in stock.
 */
std::string buildItemList(std::vector<FoodItem> dbStock)  {
    string result="";
    for(int i = 0; i < dbStock.size(); i++){
        
        if(i!= dbStock.size() -1){
            result += dbStock[i].getName() +",";
        }
        else{
            result += dbStock[i].getName();
        }
    }
    return result;
}


/**
 * @brief Sets the spoonacular API Key.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @param key The API key.
 */
void FoodAPI::setAPIKey(string key){
    FoodAPI::_apiKey = key;
}


/**
 * @brief Returns a list of preferences in recipes.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @return A list of string preferences.
 */
vector<string> FoodAPI::getPreferences() {
    return this->preferences;
}


/**
 * @brief Sets a list of preferences in recipes.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @param prefs List of preferences to set.
 */
void FoodAPI::setPreferences(vector<string> prefs){
    this->preferences = prefs;
}


/**
 * @brief Returns a list of stored recipes.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @return A list of recipes.
 */
vector<Recipe> FoodAPI::getRecipes(){
    return recipes;
}


/**
 * @brief Sets the recipes list.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @param recipes List of recipes to set.
 */
void FoodAPI::setReceipes(std::vector<Recipe> recipes){
    this->recipes = recipes;
}


/**
 * @brief Gets recipes with ingredient list from Spoonacular API.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @author Andrew Li
 * @param _theModel String of comma separated items.
 * 
 * @return Json of recipes found.
 */
std::vector<Recipe> FoodAPI::getRecipeByIngredients(void* _theModel) const{
    Model* mod = (Model*)_theModel;
    CURL *curl;
    CURLcode res;
    FILE *jsonFile = fopen("apiCall.json","w+");
    vector<FoodItem> stock = mod->queryAllFoodItems();
    string result="";
    for(int i = 0; i < stock.size(); i++){
        
        if(i!= stock.size() -1){
            result += stock[i].getName() +",";
        }
        else{
            result += stock[i].getName();
        }
    }
   
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, buildQueryURL(result).c_str());
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,jsonFile);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
   
        /* Perform the request, res will get the return code */
        
        res = curl_easy_perform(curl);
     

        /* Check for errors */
        if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    ifstream file("apiCall.json");
    Json::Value jsonObj;
    Json::Reader reader;
    reader.parse(file,jsonObj);
    //cout<<jsonObj.toStyledString()<<endl;
    vector<Recipe> recipies;
    for(Json::Value::ArrayIndex i = 0; i!=jsonObj.size(); i++){
            //For loop for making RecipeItems for missed ingredients
            vector<RecipeItem> used;
            vector<RecipeItem> missing;
            map<string, float> n;   //to be possibly implemented
            string name = stripQuotes(jsonObj[i]["title"].toStyledString()); 
            string imgURL = stripQuotes(jsonObj[i]["image"].toStyledString());
            for(Json::Value::ArrayIndex j = 0; j!=jsonObj[i]["missedIngredients"].size(); j++){
                missing.push_back(RecipeItem(regex_replace(stripQuotes(jsonObj[i]["missedIngredients"][j]["name"].toStyledString()),regex("\\r\\n|\\r|\\n"),""), 
                                    jsonObj[i]["missedIngredients"][j]["amount"].asFloat(), 
                                    regex_replace(stripQuotes(jsonObj[i]["missedIngredients"][j]["unit"].toStyledString()),regex("\\r\\n|\\r|\\n"),"")));
            }
            for(Json::Value::ArrayIndex j = 0; j!=jsonObj[i]["usedIngredients"].size(); j++){
                used.push_back(RecipeItem(regex_replace(stripQuotes(jsonObj[i]["usedIngredients"][j]["name"].toStyledString()),regex("\\r\\n|\\r|\\n"),""), 
                                    jsonObj[i]["usedIngredients"][j]["amount"].asFloat(), 
                                    regex_replace(stripQuotes(jsonObj[i]["usedIngredients"][j]["unit"].toStyledString()),regex("\\r\\n|\\r|\\n"),"")));
            }
            //push recipe to vector after all used/missing recipe items are retreived
            recipies.push_back(Recipe(name, used,missing, n,imgURL));
        }
    fclose(jsonFile);
   return recipies;
}


/**
 * @brief Checks for and returns a list of recipes that use a specific ingredient.
 * 
 * @param query The ingredient to search for.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @author Andrew Li
 * @return A list of all the recipes that use the specified ingredient.
 */
std::vector<Recipe> FoodAPI::getRecipeBySpecificIngredients(string query) const{
    CURL *curl;
    CURLcode res;
    FILE *jsonFile = fopen("apiCall.json","w+");
    bool flag = true;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, buildQueryURL(query).c_str());
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,jsonFile);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
   
        /* Perform the request, res will get the return code */
        
        res = curl_easy_perform(curl);
     

        /* Check for errors */
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
                flag = false;
        }
        
    
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    vector<Recipe> recipies;
    if(flag ==false){
        return recipies;
    }
    else{
        ifstream file("apiCall.json");
        Json::Value jsonObj;
        Json::Reader reader;
        reader.parse(file,jsonObj);
        vector<Recipe> recipies;
        for(Json::Value::ArrayIndex i = 0; i!=jsonObj.size(); i++){
                //For loop for making RecipeItems for missed ingredients
                vector<RecipeItem> used;
                vector<RecipeItem> missing;
                map<string, float> n;   //to be possibly implemented
                string name = stripQuotes(jsonObj[i]["title"].toStyledString()); 
                string imgURL = stripQuotes(jsonObj[i]["image"].toStyledString());
                for(Json::Value::ArrayIndex j = 0; j!=jsonObj[i]["missedIngredients"].size(); j++){
                    missing.push_back(RecipeItem(regex_replace(stripQuotes(jsonObj[i]["missedIngredients"][j]["name"].toStyledString()),regex("\\r\\n|\\r|\\n"),""), 
                                        jsonObj[i]["missedIngredients"][j]["amount"].asFloat(), 
                                        regex_replace(stripQuotes(jsonObj[i]["missedIngredients"][j]["unit"].toStyledString()),regex("\\r\\n|\\r|\\n"),"")));
                }
                for(Json::Value::ArrayIndex j = 0; j!=jsonObj[i]["usedIngredients"].size(); j++){
                    used.push_back(RecipeItem(regex_replace(stripQuotes(jsonObj[i]["usedIngredients"][j]["name"].toStyledString()),regex("\\r\\n|\\r|\\n"),""), 
                                        jsonObj[i]["usedIngredients"][j]["amount"].asFloat(), 
                                        regex_replace(stripQuotes(jsonObj[i]["usedIngredients"][j]["unit"].toStyledString()),regex("\\r\\n|\\r|\\n"),"")));
                }
                //push recipe to vector after all used/missing recipe items are retreived
                recipies.push_back(Recipe(name, used,missing, n,imgURL));
            }
        fclose(jsonFile);
   return recipies;
    }
    
}


/**
 * @brief Removes unneccesary punctuation from strings and returns it.
 * 
 * @param line The string to remove the punctuation from.
 * @author Matthew Cheverie
 * @return The stripped string.
 */
string FoodAPI::stripQuotes(string line) const{
    line.erase(std::remove(line.begin(),line.end(),'\"'),line.end());
    return line;
}


/**
 * @brief Adds a preference to the preference list.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @param pref The string name of the preference to add.
 */
void FoodAPI::addPreference(std::string pref){
    if(std::find(preferences.begin(), preferences.end(), pref)==preferences.end()){
        preferences.push_back(pref);
    }
}


/**
 * @brief Removes a preference from the preference list.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @param pref The string name of the preference to remove.
 */
void FoodAPI::removePreference(std::string pref){
    preferences.erase(std::remove(preferences.begin(), preferences.end(), pref), preferences.end());
}


/**
 * @brief Builds and returns the query URL.
 * 
 * @param itemList The string of the ingredients.
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @return The query URL.
 */
string FoodAPI::buildQueryURL(string itemList) const{
    string URL = "https://api.spoonacular.com/recipes/findByIngredients?apiKey="+this->getAPIKey()+"&ingredients="+itemList+"&number=5&ranking=2&ignorePantry=true";
    return URL;
    
}


/**
 * @brief Destructor - Deletes instance of FoodAPI.
 * @author Matthew Cheverie
 * @author Jared Anstett
 */
FoodAPI::~FoodAPI(){
    delete _instance;
}
