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
        std::string recipeName; /**< string: The name of the recipe */
        std::vector<RecipeItem> recipeIngredients; /**< vector<RecipeItem>: All the ingredients in the recipe */
        std::map<std::string, int> recipeNutrition; /**< map<std::string, int>: All the nutrients / macros of recipe */
        float recipeYield; /**< float: The yield of the recipe in servings */
    public:
        /**
         * @brief construct the recipe object
         * @author Andrew Li
         */
        Recipe();
        /**
         * @brief construct the recipe object
         * @param rname         : name of recipe
         * @param ingredients   : vector of all recipe ingredients
         * @param nutri         : map of all the nutrients
         * @author Andrew Li
         */
        Recipe(std::string rname, std::vector<RecipeItem> ingredients, std::map<std::string, int> nutri);
        /**
         * @brief destroy the recipe object
         * @author Andrew Li
         */
        ~Recipe();
        /**
         * @brief access name of the recipe
         * @return a strings of the name of the recipe
         * @author Andrew Li
         */
        std::string getRecipeName();
        /**
         * @brief access all the ingredients of recipe
         * @return a vector connecting all RecipeItems
         * @author Andrew Li
         */
        std::vector<RecipeItem> getIngredients();
        /**
         * @brief access all the nutrition values of recipe
         * @return a map connecting nutrient with values
         * @author Andrew Li
         */
        std::map<std::string, int> getNutrition();
        /**
         * @brief updates all RecipeItems to create the quantity yield given 
         * @param newYield : the new yield of the recipe after all changes made
         * @author Kanishk Mishra
         */
        void changeProportions(float newYield);
        /**
         * @brief exchange one recipe ingredient for one in our inventory
         * @param nItem : the new ingredient to swap in
         * @param rItem : the old ingredient to swap out
         * @author Kanishk Mishra
         */
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
         */
        int adjustIngredientAmount(FoodItem item, float quantity);
};

#endif

