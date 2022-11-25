#ifndef RECIPE_H
#define RECIPE_H

#include <vector>
#include <map>
#include "FoodItem.h"
#include "RecipeItem.h"


/**
 * @brief This class stores and allows the user to amnipulate specific recipes
 * @author Kanishk Mishra
 * @author Andrew Li
 */
class Recipe{
    private:
        std::string recipeName;
        std::string recipeProperties;
        std::vector<RecipeItem> missingIngredients;
        std::vector<RecipeItem> recipeIngredients;
        std::map<std::string,float> recipeNutrition;
        
    public:
        Recipe();
        Recipe(std::string rname, std::vector<RecipeItem> ingredients,std::vector<RecipeItem> missingingredients, std::map<std::string, float> nutri);
        ~Recipe();
        std::string getRecipeName();
        std::vector<RecipeItem> getIngredients();
        std::map<std::string, float> getNutrition();    
        void swapIngredient(FoodItem nItem, RecipeItem rItem);
        int adjustIngredientAmount(FoodItem item, float quantity);
        int addIngredient(FoodItem nItem);
};

#endif

