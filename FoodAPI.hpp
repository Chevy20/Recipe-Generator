#ifndef FOODAPI_H
#define FOODAPI_H

#include <string>
#include <vector>
#include "Recipe.h"

class FoodAPI {
    private:
        // Singleton setup
        static const FoodAPI* _instance; 
        FoodAPI(const FoodAPI& other);
        //FoodAPI& operator=(const FoodAPI& other);

        std::vector<std::string> preferences;
        std::vector<Recipe> recipes;
        std::string _apiKey;

    protected:
        FoodAPI();  // Prevent instantiation

    public:
        virtual ~FoodAPI();
        static const FoodAPI& getInstance();
        const FoodAPI& operator<<(const std::string& message) const;

        std::string getAPIKey() const;
        void setAPIKey(std::string key);
        std::vector<std::string> getPreferences();
        void setPreferences(std::vector<std::string> prefs);
        std::vector<Recipe> getRecipes();
        void setReceipes(std::vector<Recipe> recipes);
        std::vector<Recipe> getRecipeByIngredients(std::string itemList);
        void addPreference(std::string pref);
        void removePreference(std::string pref);
        std::string buildQueryURL(std::string baseURL, std::vector<std::string> items);
};

#endif