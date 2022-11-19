#include <iostream>
#include <math.h>
#include "Recipe.h"
using namespace std;

Recipe::Recipe()
{
    //default     
}
Recipe::Recipe(std::string rname, std::vector<RecipeItem> ingredients, std::map<std::string, int> nutri)
{
    recipeName = rname;
    recipeIngredients = ingredients;
    recipeNutrition = nutri;
}
Recipe::~Recipe()
{

}
string Recipe::getRecipeName()
{
    return recipeName;
}
vector<RecipeItem> Recipe::getIngredients()
{
    return recipeIngredients;
}
map<string, int> Recipe::getNutrition()
{
    return recipeNutrition;
}
/*
 * Function: changeProportions 
 * Description: updates all RecipeItems to create the quantity given
 * Parameters: float newYield : the new yield of the recipe after all chnages made
 * Return: nothing
 */
void Recipe::changeProportions(float newYield)
{
    float change = newYield / recipeYield;
    for(RecipeItem food : recipeIngredients){
        float quantity = food.getQuantity() * change;
        quantity = ceil(quantity * 100.0) / 100.0;
        food.setQuantity(quantity);
    }
    recipeYield = newYield;
}
/*
 * Function: swapIngredient 
 * Description: updates all RecipeItems to create the quantity given
 * Parameters: FoodItem nItem : the new food item to be swapped in, RecipeItem rItem: the item in recipe swapped out
 * Return: nothing
 */
void Recipe::swapIngredient(FoodItem nItem, RecipeItem rItem)
{
    rItem.setItem(nItem);
    rItem.setQuantity(0);
    rItem.setItemMeasureUnit(nItem.getMeasureUnit());
}
/*
 * Function: addIngredient 
 * Description: add RecipeItem to vector of ingredients given
 * Parameters: FoodItem nItem : the new food item to be added in, float quantity: the quantity of ingredients
 * Return: -1, item failed to add, already exists
 */
int Recipe::addIngredient(FoodItem nItem)
{
    RecipeItem ingredient;
    ingredient.setItem(nItem);
    ingredient.setItemMeasureUnit(nItem.getMeasureUnit());
    ingredient.setQuantity(0);

    for(RecipeItem food : recipeIngredients){
        if(food.getItem().getName() == nItem.getName()){
            return -1;
        }
    }

    recipeIngredients.push_back(ingredient);
    
}
/*
 * Function: adjustIngredientAmount 
 * Description: updates a RecipeItem to the quantity given
 * Parameters: FoodItem item : check which Recipe item to change, int quantity: the new val to update to
 * Return: -1, food item does not exist
 */
int Recipe::adjustIngredientAmount(FoodItem item, float quantity)
{
    for(RecipeItem food : recipeIngredients){
        if(food.getItem().getName() == item.getName()){
            food.setQuantity(quantity);
            return 0;
        }
    }
    return -1;
}