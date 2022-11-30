#include <iostream>
#include <math.h>
#include "Recipe.h"
using namespace std;


/**
 * Constructor - Sets all the variables for this class.
 */
Recipe::Recipe()
{
    //default     
}


/**
 * Constructor - Sets all the variables for this class.
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
 * Destructor
 */
Recipe::~Recipe()
{

}


/**
 * Returns a list of the missing ingredients required for the recipe.
 * 
 * @return The list of missing ingredients.
 */
vector<RecipeItem> Recipe::getMissingIngredients(){
    return missingIngredients;
}


/**
 * Returns the url of the image of the recipe.
 * 
 * @return The string of the image source.
 */
string Recipe::getImageURL(){
    return imageURL;
}


/**
 * Returns the name of the recipe.
 * 
 * @return The string of the recipe name.
 */
string Recipe::getRecipeName()
{
    return recipeName;
}


/**
 * Returns the list of the ingredients for the recipe.
 * 
 * @return The ingredient list for the recipe.
 */
vector<RecipeItem> Recipe::getIngredients()
{
    return recipeIngredients;
}


/**
 * Returns the nutrition of the recipe.
 * 
 * @return The recipe's nutrition.
 */
map<string, float> Recipe::getNutrition()
{
    return recipeNutrition;
}


/*
 * Function: swapIngredient 
 * Description: updates all RecipeItems to create the quantity given
 * Parameters: FoodItem nItem : the new food item to be swapped in, RecipeItem rItem: the item in recipe swapped out
 * Return: nothing
 */
 void swapIngredient(std::string nItem, float nQuan, string nMeasure, RecipeItem rItem)
{
    rItem.setItem(nItem);
    rItem.setQuantity(nQuan);
    rItem.setItemMeasureUnit(nMeasure);
}


/*
 * Function: addIngredient 
 * Description: add RecipeItem to vector of ingredients given
 * Parameters: FoodItem nItem : the new food item to be added in, float quantity: the quantity of ingredients
 * Return: -1, item failed to add: already exists
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


/*
 * Function: adjustIngredientAmount 
 * Description: updates a RecipeItem to the quantity given
 * Parameters: FoodItem item : check which Recipe item to change, int quantity: the new val to update to
 * Return: -1, food item does not exist
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
