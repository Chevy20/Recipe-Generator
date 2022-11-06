#ifndef RECIPE_H
#define RECIPE_H

#include <vector>
#include <map>
#include "FoodItem.h"
#include "RecipeItem.h"
class Recipe{
    private:
        std::string recipeName;
        std::string recipeProperties;
        std::vector<RecipeItem> recipeIngredients;
        std::map<std::string, int> recipeNutrition;
        float recipeYeild;
    public:
        Recipe();
        Recipe(std::string rname, std::vector<RecipeItem> ingredients, std::map<std::string, int> nutri);
        ~Recipe();
        std::string getRecipeName();
        std::vector<RecipeItem> getIngredients();
        std::map<std::string, int> getNutrition();
        void updateStock();
        void changeProportions(float newYield);
        void swapIngredient();
        int adjustIngredientAmount(FoodItem item, int quantity);
};

#endif

