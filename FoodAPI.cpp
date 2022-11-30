
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <algorithm>
#include "FoodAPI.hpp"
#include "Model.h"
#include <regex>
using namespace std;

const FoodAPI* FoodAPI::_instance = NULL;
/*
Function: getInstance()
Description: Returns a single instance of the FoodAPI
Parameters: none
Return: _instance - single instance of the FoodAPI object   
*/
const FoodAPI& FoodAPI::getInstance(){
    if(_instance == NULL) {
        _instance = new FoodAPI();
    }
    return *_instance;
}

/*
Function: FoodAPI()
Description: Constructor
Parameters: none
Return: none
*/
FoodAPI::FoodAPI(){
    string key = "254ee65b4d89431f9465d6b595199032";
    FoodAPI::setAPIKey(key);
    
    
}

/*
Function: getAPIKey()
Description: sets the spoonacular API Key
Parameters: key - api key
Return: None
*/
string FoodAPI::getAPIKey() const{
    return this->_apiKey;
}
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
/*
Function: setAPIKey()
Description: sets the spoonacular API Key
Parameters: key - api key
Return: None
*/
void FoodAPI::setAPIKey(string key){
    FoodAPI::_apiKey = key;
}

/*
Function: getPreferences()
Description: Returns a vector of preferences in recipes
Parameters: none
Return: preferences - vector of string preferences
*/
vector<string> FoodAPI::getPreferences() {
    return this->preferences;
}

/*
Function: setPreferences()
Description: Sets a vector of preferences in recipes
Parameters: vector<string> - vector of preferences
Return: None
*/
void FoodAPI::setPreferences(vector<string> prefs){
    this->preferences = prefs;
}


/*
Function: getRecipes()
Description: Returns a vector of stored recipes
Parameters: None
Return: recipes - vector of recipes
*/
vector<Recipe> FoodAPI::getRecipes(){
    return recipes;
}

/*
Function: setRecipes()
Description: Sets the recipes vector
Parameters: recipes - vector of recipes
Return: None
*/
void FoodAPI::setReceipes(std::vector<Recipe> recipes){
    this->recipes = recipes;
}

/*
Function: getRecipeByIngredients()
Description: Gets recipes with ingredient list from Spoonacular API
Parameters: itemList - string of comma separated items
Return: res - Json of recipes found
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

string FoodAPI::stripQuotes(string line) const{
    line.erase(std::remove(line.begin(),line.end(),'\"'),line.end());
    return line;
}

/*
Function: addPreference()
Description: Adds a preference to the preference vector
Parameters: pref - string name of the preference to add
Return: None
*/
void FoodAPI::addPreference(std::string pref){
    if(std::find(preferences.begin(), preferences.end(), pref)==preferences.end()){
        preferences.push_back(pref);
    }
}

/*
Function: removePreference()
Description: Removes a preference from the preference vector
Parameters: pref - string name of the preference to remove
Return: None
*/
void FoodAPI::removePreference(std::string pref){
    preferences.erase(std::remove(preferences.begin(), preferences.end(), pref), preferences.end());
}
        
/*
Function: buildQueryURL()
Description: Removes a preference from the preference vector
Parameters: pref - string name of the preference to remove
Return: None
*/
string FoodAPI::buildQueryURL(string itemList) const{
    string URL = "https://api.spoonacular.com/recipes/findByIngredients?apiKey="+this->getAPIKey()+"&ingredients="+itemList+"&number=5&ranking=2&ignorePantry=true";
    return URL;
    
}

/*
Function: ~FoodAPI()
Description: Destructor deletes instance of FoodAPI
Parameters: None
Return: None
*/
FoodAPI::~FoodAPI(){
    delete _instance;
}
// //Testing, to be removed later
// int main(){
    
    
//     Model* modl = new Model();
    
//     FoodItem item1 = FoodItem("apples",4,"apples","2022/11/25","2022/11/30","fridge",1);
//     FoodItem item2 = FoodItem("flour",4,"cups","2022/11/25","2022/11/30","pantry",1);
//     FoodItem item3 = FoodItem("sugar",4,"cups","2022/11/25","2022/11/30","fridge",1);
//     /*
//     modl->addFoodItem(item1);
//     modl->addFoodItem(item2);
//     modl->addFoodItem(item3);
//     */
    
//     modl->getFoodAPI()->getRecipeByIngredients(modl);
    
// }


