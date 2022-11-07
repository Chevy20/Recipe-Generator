
#include <string>
#include <vector>
#include "Recipe.h"

class FoodAPIClass {
    private:
        std::vector<string> preferences;
        std::vector<Recipe> recipes;

    public:
        FoodAPIClass();
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