#ifndef RECIPE_H
#define RECIPE_H

#include <vector>
#include <map>
#include "FoodItem.h"
#include "RecipeItem.h"


/**
 * @brief This class stores and allows the user to manipulate specific recipes
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
        std::string imageURL;
       
        
        
    public:
        /**
         * @brief Constructor - Sets all the variables for this class.
         */
        Recipe();
        /**
         * @brief Constructor - Sets all the variables for this class.
         * 
         * @param rname The name of the recipe.
         * @param ingredients The list of ingredients required for the recipe.
         * @param missingingredients List of any ingredients that are missing from the stock.
         * @param nutri The nutrition of the recipe.
         * @param img The image source for the picture of the recipe.
         */
        Recipe(std::string rname, std::vector<RecipeItem> ingredients,std::vector<RecipeItem> missingingredients, std::map<std::string, float> nutri, std::string img);
        /**
         * @brief Destructor
         */
        ~Recipe();
        /**
         * @brief Returns the name of the recipe.
         * 
         * @return The string of the recipe name.
         */
        std::string getRecipeName();
        /**
         * @brief Returns the url of the image of the recipe.
         * 
         * @return The string of the image source.
         */
        std::string getImageURL();
        /**
         * @brief Returns a list of the missing ingredients required for the recipe.
         * 
         * @return The list of missing ingredients.
         */
        std::vector<RecipeItem> getMissingIngredients();
        /**
         * @brief Returns the list of the ingredients for the recipe.
         * 
         * @return The ingredient list for the recipe.
         */
        std::vector<RecipeItem> getIngredients();
        /**
         * @brief Returns the nutrition of the recipe.
         * 
         * @return The recipe's nutrition.
         */
        std::map<std::string, float> getNutrition();    
        /**
         * @brief Overwrites a food item with a new item.
         * 
         * @param nItem The name of the new food item to be swapped in.
         * @param nQuan The quantity of the new food item to be swapped in.
         * @param nMeasure The measurement of the new food item to be swapped in.
         */
        void swapIngredient(std::string nItem, float nQuan, std::string nMeasure, RecipeItem rItem);
        /**
         * @brief Adjusts the ingredient amount for a recipe.
         * 
         * @param item The ingredient to adjust.
         * @param quantity The new quantity.
         * 
         * @return Int used as a boolean of success.
         */
        int adjustIngredientAmount(RecipeItem item, float quantity);
        /**
         * @brief Adds an ingredient to a recipe.
         * 
         * @param nItem The recipe to add to.
         * 
         * @return Int used as a boolean of success. -1 if duplicate ingredient. 0 otherwise.
         */
        int addIngredient(RecipeItem nItem);
};

#endif

