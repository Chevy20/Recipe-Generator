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

FoodAPIClass* FoodAPIClass::getInstance(){
    if(_instance == NULL) {
        _instance = new FoodAPIClass();
    }
    return(_instance);
}

vector<string> FoodAPIClass::getPreferences() {
    return this->preferences;
}

void FoodAPIClass::setPreferences(vector<string> prefs){
    this->preferences = pref;
}

vector<Recipe> FoodAPIClass::getRecipes(){
    return recipes;
}

void FoodAPIClass::setReceipes(std::vector<Recipe> recipes){
    this->recipes = recipes;
}
    
vector<Recipe> FoodAPIClass::getRecipeByIngredients(std::string itemList){
    
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
    
void FoodAPIClass::addPreference(std::string pref){
    if(!(preferences.find(preferences.begin(), preferences.end(), pref))){
        preferences.push_back(pref);
    }
}
    
void FoodAPIClass::removePreference(std::string pref){
    preferences.erase(std::remove(preferences.begin(), preferences.end(), pref), preferences.end());
}
        
vector<Recipe> FoodAPIClass::sortListRecipeByPreference(){

}

void FoodAPIClass::buildQueryURL(std::string baseUrl, std::string){

}



~FoodAPIClass(){
    delete _instance;
}

