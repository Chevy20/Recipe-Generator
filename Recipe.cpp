#include <iostream>
#include <math.h>
#include "Recipe.h"
using namespace std;


/**
 * @brief Constructor - Sets all the variables for this class.
 */
Recipe::Recipe()
{
    //default     
}


/**
 * @brief Constructor - Sets all the variables for this class.
 * 
 * @param rname The name of the recipe.
 * @param ingredients The list of ingredients required for the recipe.
 * @param missingingredients List of any ingredients that are missing from the stock.
 * @param nutri The nutrition of the recipe.
 * @param img The image source for the picture of the recipe.
 */
Recipe::Recipe(std::string rname, std::vector<RecipeItem> ingredients,std::vector<RecipeItem> missingingredients, std::map<std::string, float> nutri, std::string img)
{
    recipeName = rname;
    missingIngredients = missingingredients;
    recipeIngredients = ingredients;
    recipeNutrition = nutri;
    imageURL = img;
   
    
}


/**
 * @brief Destructor
 */
Recipe::~Recipe()
{

}


/**
 * @brief Returns a list of the missing ingredients required for the recipe.
 * 
 * @return The list of missing ingredients.
 */
vector<RecipeItem> Recipe::getMissingIngredients(){
    return missingIngredients;
}


/**
 * @brief Returns the url of the image of the recipe.
 * 
 * @return The string of the image source.
 */
string Recipe::getImageURL(){
    return imageURL;
}


/**
 * @brief Returns the name of the recipe.
 * 
 * @return The string of the recipe name.
 */
string Recipe::getRecipeName()
{
    return recipeName;
}


/**
 * @brief Returns the list of the ingredients for the recipe.
 * 
 * @return The ingredient list for the recipe.
 */
vector<RecipeItem> Recipe::getIngredients()
{
    return recipeIngredients;
}


/**
 * @brief Returns the nutrition of the recipe.
 * 
 * @return The recipe's nutrition.
 */
map<string, float> Recipe::getNutrition()
{
    return recipeNutrition;
}


/**
 * @brief Overwrites a food item with a new item.
 * 
 * @param nItem The name of the new food item to be swapped in.
 * @param nQuan The quantity of the new food item to be swapped in.
 * @param nMeasure The measurement of the new food item to be swapped in.
 */
void swapIngredient(std::string nItem, float nQuan, string nMeasure, RecipeItem rItem)
{
    rItem.setItem(nItem);
    rItem.setQuantity(nQuan);
    rItem.setItemMeasureUnit(nMeasure);
}


/**
 * @brief Adds an ingredient to a recipe.
 * 
 * @param nItem The recipe to add to.
 * 
 * @return Int used as a boolean of success. -1 if duplicate ingredient. 0 otherwise.
 */
int Recipe::addIngredient(RecipeItem nItem)
{
    
   
    for(RecipeItem food : recipeIngredients){
        if(food.getItem() == nItem.getItem()){
           
            cout<< "Duplicate Ingredient. Cannot add" <<endl;
            return -1;
        }
        
    }
        recipeIngredients.push_back(nItem);
        return 0;
    
}


/**
 * @brief Adjusts the ingredient amount for a recipe.
 * 
 * @param item The ingredient to adjust.
 * @param quantity The new quantity.
 * 
 * @return Int used as a boolean of success.
 */
int Recipe::adjustIngredientAmount(RecipeItem item, float quantity)
{
    for(RecipeItem food : recipeIngredients){
        if(food.getItem() == item.getItem()){
            food.setQuantity(quantity);
            return 0;
        }
    }

    return -1;
}
