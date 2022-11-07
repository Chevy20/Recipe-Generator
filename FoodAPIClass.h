#ifndef FOODAPICLASS_H
#define FOODAPICLASS_H

#include <string>
#include <vector>
#include "Recipe.h"

class FoodAPIClass {
    private:
        // Singleton setup
        static FoodAPIClass* _instance; 
        FoodAPIClass();
        FoodAPIClass(const FoodAPIClass&);
        FoodAPIClass& operator=(const FoodAPIClass&);

        std::vector<string> preferences;
        std::vector<Recipe> recipes;


    public:
        static FoodAPIClass* getInstance();
        ~FoodAPIClass();

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