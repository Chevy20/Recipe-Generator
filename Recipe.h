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
        std::vector<RecipeItem> recipeIngredients;
        std::map<std::string,int> recipeNutrition;
        float recipeYield;
    public:
        Recipe();
        Recipe(std::string rname, std::vector<RecipeItem> ingredients, std::map<std::string, int> nutri);
        ~Recipe();
        std::string getRecipeName();
        std::vector<RecipeItem> getIngredients();
        std::map<std::string, int> getNutrition();
        void changeProportions(float newYield);
        void swapIngredient(FoodItem nItem, RecipeItem rItem);
        /**
         * @brief add one recipe ingredient fron our inventory
         * @param nItem : the new item from our inventory to add
         * @return 0    : successfully added
         * @return -1   : addition unsuccessful
         * @author Kanishk Mishra
         */
        int addIngredient(FoodItem nItem);
        /**
         * @brief updates one RecipeItem to change the quantity yield given 
         * @param item      : the item to change quantity of
         * @param quantity  : the quantity to change to
         * @return 0        : adjustment successful
         * @return -1       : nothing was adjusted
         * @author Andrew Li
         * @author Kanishk Mishra
         */
        int adjustIngredientAmount(FoodItem item, float quantity);
};

#endif

