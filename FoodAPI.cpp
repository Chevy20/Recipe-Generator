#include "FoodAPI.h"
#include "HTTPRequest.h"
#include "com.spoonacular.client.model"

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

void FoodAPIClass::setPreferences(string pref){
    this->preferences = pref;
}

vector<Recipe> FoodAPIClass::getRecipes(){

    try
    {
        // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
        http::Request request{"http://test.com/test"};

        // send a get request
        const auto response = request.send("GET");
        std::cout << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }

}

void FoodAPIClass::setReceipes(std::vector<Recipe> recipes){

}
    
vector<Recipe> FoodAPIClass::getRecipeByIngredients(std::string itemList){

}
    
void FoodAPIClass::addPreference(std::string pref){

}
    
void FoodAPIClass::removePreference(std::string pref){

}
        
vector<Recipe> FoodAPIClass::sortListRecipeByPreference(){

}

void FoodAPIClass::buildQueryURL(){

}



~FoodAPIClass(){
    delete _instance;
}

