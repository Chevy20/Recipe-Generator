#ifndef FOODAPI_H
#define FOODAPI_H

#include <string>
#include <vector>
#include "Recipe.h"

class FoodAPI {
    private:
        // Singleton setup
        static FoodAPI* _instance; 
        FoodAPI();
        FoodAPI(const FoodAPI&);
        FoodAPI& operator=(const FoodAPI&);

        std::vector<std::string> preferences;
        std::vector<Recipe> recipes;

    public:
        static FoodAPI* getInstance();
        ~FoodAPI();

        std::vector<std::string> getPreferences();
        void setPrefences(std::vector<string> prefs);
        std::vector<Recipe> getRecipes();
        void setReceipes(std::vector<Recipe> recipes);
        std::vector<Recipe> getRecipeByIngredients(std::string itemList);
        void addPreference(std::string pref);
        void removePreference(std::string pref);
        std::vector<Recipe> sortListRecipeByPreference();
        void buildQueryURL();
};

#endif