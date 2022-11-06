#include <iostream>
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
void Recipe::updateStock()
{

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
        float quantity = food.getQuantity();
        quantity = ((quantity + 0.5/2) / 0.5) * 0.5;
        food.setQuantity(quantity * change);
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
    rItem.setQuantity(1);
    rItem.setItemMeasureUnit(nItem.getMeasureUnit());
}
/*
 * Function: adjustIngredientAmount 
 * Description: updates a RecipeItem to the quantity given
 * Parameters: FoodItem item : check which Recipe item to change, int quantity: the new val to update to
 * Return: -1, food item does not exist
 */
int Recipe::adjustIngredientAmount(FoodItem item, int quantity)
{
    for(RecipeItem food : recipeIngredients){
        if(food.getItem().getName() == item.getName()){
            food.setQuantity(quantity);
            return 0;
        }
    }
    return -1;
}