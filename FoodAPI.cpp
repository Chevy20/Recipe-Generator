
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
// #include <json/json.h>
#include <fstream>
#include <algorithm>
#include "FoodAPI.hpp"

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
vector<Recipe> FoodAPI::getRecipeByIngredients(std::string itemList){
    
    CURL *curl;
    CURLcode res;
    string BASE_URL = "https://api.spoonacular.com/recipes/findByIngredients";



    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.spoonacular.com/recipes/findByIngredients?apiKey=de32085d5f03454bbccdad302c309955&ingredients=apples");
    
   
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
    
    return recipes;
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
string FoodAPI::buildQueryURL(std::string baseURL, vector<string> items){
    
}

/*
Function: ~FoodAPI()
Description: Destructor deletes instance of FoodAPI
Parameters: None
Return: None
*/
FoodAPI::~FoodAPI(){

}

// int main(){
    
//     const FoodAPI* ap = &FoodAPI::getInstance();
//     cout << ap->getAPIKey() << endl;
// }
