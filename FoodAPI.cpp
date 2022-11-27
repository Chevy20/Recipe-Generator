
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <algorithm>
#include "FoodAPI.hpp"
#include "Model.h"

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
    
    if(const char* envVar = getenv("SPOONACULAR_API_KEY")){
        std::string key = envVar;
        FoodAPI::setAPIKey(key);
    }
    else{
        cout << "Missing API Key.  Add to environment variables." << endl;
        exit(0);
    }
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
            
            for(Json::Value::ArrayIndex j = 0; j!=jsonObj[i]["missedIngredients"].size(); j++){
                missing.push_back(RecipeItem(stripQuotes(jsonObj[i]["missedIngredients"][j]["name"].toStyledString()), 
                                    jsonObj[i]["missedIngredients"][j]["amount"].asFloat(), 
                                    stripQuotes(jsonObj[i]["missedIngredients"][j]["unit"].toStyledString())));
            }
            for(Json::Value::ArrayIndex j = 0; j!=jsonObj[i]["usedIngredients"].size(); j++){
                used.push_back(RecipeItem(stripQuotes(jsonObj[i]["usedIngredients"][j]["name"].toStyledString()), 
                                    jsonObj[i]["usedIngredients"][j]["amount"].asFloat(), 
                                    stripQuotes(jsonObj[i]["usedIngredients"][j]["unit"].toStyledString())));
            }
            //push recipe to vector after all used/missing recipe items are retreived
            recipies.push_back(Recipe(name, used,missing, n));
            //cout<<jsonObj[i]<<endl;
        }
    
    /*
    for(int i = 0; i < recipies.size(); i++){
        cout<<"Recipe Name: "+recipies[i].getRecipeName()<<endl;;
        cout<<"Used Ingredients"<<endl;
        for(int j = 0; j < recipies[i].getIngredients().size(); j++){
            cout<<recipies[i].getIngredients()[j].getItem()<<endl;
            cout<<recipies[i].getIngredients()[j].getQuantity()<<endl;
            cout<<recipies[i].getIngredients()[j].getItemMeasureUnit()<<endl;
        }
        cout<<"Missing Ingredients"<<endl;
        for(int j = 0; j < recipies[i].getMissingIngredients().size(); j++){
            cout<<recipies[i].getMissingIngredients()[j].getItem()<<endl;
            cout<<recipies[i].getMissingIngredients()[j].getQuantity()<<endl;
            cout<<recipies[i].getMissingIngredients()[j].getItemMeasureUnit()<<endl;
        }

    }
    */
    
    
    
    //cout<<jsonObj.toStyledString()<<endl;   //remove after
    fclose(jsonFile);
   return recipies;
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




