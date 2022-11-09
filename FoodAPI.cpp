#include "FoodAPI.h"
#include "HTTPRequest.h"
#include "com.spoonacular.client.model"
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <algorithm>

namespace std;

/*
Function: getInstance()
Description: Returns a single instance of the FoodAPI
Parameters: none
Return: _instance - single instance of the FoodAPI object
*/
FoodAPI* FoodAPI::getInstance(){
    if(_instance == NULL) {
        _instance = new FoodAPI();
    }
    return(_instance);
}

/*
Function: getPreferences
Description: Returns a vector of preferences in recipes
Parameters: none
Return: preferences - vector of string preferences
*/
vector<string> FoodAPI::getPreferences() {
    return this->preferences;
}

/*
Function: setPreferences
Description: Returns a vector of preferences in recipes
Parameters: none
Return: preferences - vector of string preferences
*/
void FoodAPI::setPreferences(vector<string> prefs){
    this->preferences = pref;
}

vector<Recipe> FoodAPI::getRecipes(){
    return recipes;
}

void FoodAPI::setReceipes(std::vector<Recipe> recipes){
    this->recipes = recipes;
}
    
vector<Recipe> FoodAPI::getRecipeByIngredients(std::string itemList){
    
    CURL *curl;
    CURLcode res;
    std::string BASE_URL = "https://api.spoonacular.com/recipes/findByIngredients";

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
    
    return 0;
}
    
void FoodAPI::addPreference(std::string pref){
    if(!(preferences.find(preferences.begin(), preferences.end(), pref))){
        preferences.push_back(pref);
    }
}
    
void FoodAPI::removePreference(std::string pref){
    preferences.erase(std::remove(preferences.begin(), preferences.end(), pref), preferences.end());
}
        
vector<Recipe> FoodAPI::sortListRecipeByPreference(){

}

void FoodAPI::buildQueryURL(std::string baseUrl, std::string){

}



~FoodAPI(){
    delete _instance;
}

