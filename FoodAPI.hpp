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
        /**
         * @brief Removes unneccesary punctuation from strings and returns it.
         * 
         * @param line The string to remove the punctuation from.
         * 
         * @return The stripped string.
         */
        std::string stripQuotes(std::string line) const;
    protected:
        /**
         * @brief Constructor
         */
        FoodAPI();  // Prevent instantiation

    public:
        /**
         * @brief Destructor - Deletes instance of FoodAPI.
         */
        virtual ~FoodAPI();
        /**
         * @brief Returns a single instance of the FoodAPI.
         * 
         * @return Single instance of the FoodAPI object.
         */
        static const FoodAPI& getInstance();
        const FoodAPI& operator<<(const std::string& message) const;
        /**
         * @brief Takes the list of the ingredients in the stock and turns them into a printable string.
         * 
         * @param dbStock The stock of ingredients in the database.
         * 
         * @return The string of all the ingredients in stock.
         */
        std::string buildItemList(std::vector<FoodItem> dbStock) const;
        /**
         * @brief Gets the spoonacular API Key
         * 
         * @return The API key.
         */
        std::string getAPIKey() const;
        /**
         * @brief Sets the spoonacular API Key.
         * 
         * @param key The API key.
         */
        void setAPIKey(std::string key);
        /**
         * @brief Returns a list of preferences in recipes.
         * 
         * @return A list of string preferences.
         */
        std::vector<std::string> getPreferences();
        /**
         * @brief Sets a list of preferences in recipes.
         * 
         * @param prefs List of preferences to set.
         */
        void setPreferences(std::vector<std::string> prefs);
        /**
         * @brief Returns a list of stored recipes.
         * 
         * @return A list of recipes.
         */
        std::vector<Recipe> getRecipes();
        /**
         * @brief Sets the recipes list.
         * 
         * @param recipes List of recipes to set.
         */
        void setReceipes(std::vector<Recipe> recipes);
        /**
         * @brief Gets recipes with ingredient list from Spoonacular API.
         * 
         * @param _theModel String of comma separated items.
         * 
         * @return Json of recipes found.
         */
        std::vector<Recipe> getRecipeByIngredients(void* theModel) const;
        /**
         * @brief Checks for and returns a list of recipes that use a specific ingredient.
         * 
         * @param query The ingredient to search for.
         * 
         * @return A list of all the recipes that use the specified ingredient.
         */
        std::vector<Recipe> getRecipeBySpecificIngredients(std::string query) const;
        /**
         * @brief Adds a preference to the preference list.
         * 
         * @param pref The string name of the preference to add.
         */
        void addPreference(std::string pref);
        /**
         * @brief Removes a preference from the preference list.
         * 
         * @param pref The string name of the preference to remove.
         */
        void removePreference(std::string pref);
        /**
         * @brief Builds and returns the query URL.
         * 
         * @param itemList The string of the ingredients.
         * 
         * @return The query URL.
         */
        std::string buildQueryURL(std::string itemList) const;
};

#endif
