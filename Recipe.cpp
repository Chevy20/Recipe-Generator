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
void Recipe::changeProportions()
{

}
void Recipe::swapIngredient()
{

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