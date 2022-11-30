#include <iostream>
#include "RecipeItem.h"

using namespace std;


/**
 * @brief construct the recipe ingredient
 * @author Andrew Li
 */
RecipeItem::RecipeItem()
{

}


/**
 * @brief construct the recipe ingredient
 * @param fitem : the string of the name of food item 
 * @param num   : the quantity in numeric value
 * @param unit  : the string of the unit of the quantity of the ingredient
 * @author Andrew Li
 * @author Kanishk Mishra
 */
RecipeItem::RecipeItem(string fitem, float num, string unit)
{
    item = fitem;
    itemQty = num;
    itemMeasureUnit = unit;
}


/**
 * @brief destroy the recipe ingredient
 * @author Andrew Li
 */
RecipeItem::~RecipeItem()
{

}


/**
 * @brief access the original ingredient in inventory
 * @return the original FoodItem
 * @author Andrew Li
 */
string RecipeItem::getItem()
{
    return item;
}


/**
 * @brief access the numeric quantity of ingredient
 * @return the number of items
 * @author Andrew Li
 */
float RecipeItem::getQuantity()
{
    return itemQty;
}


/**
 * @brief access the measurement of the ingredient
 * @return string of the unit of measurement
 * @author Andrew Li
 */
string RecipeItem::getItemMeasureUnit()
{
    return itemMeasureUnit;
}


/**
 * @brief change the original ingredient in inventory
 * @param fitem : the new FoodItem from inventory
 * @author Andrew Li
 */
void RecipeItem::setItem(string fItem)
{
    item = fItem;
}


/**
 * @brief change the numerical quantity in recipe
 * @param qty   : float for the quantity of ingredients
 * @author Andrew Li
 * @author Kanishk Mishra
 */
void RecipeItem::setQuantity(float num)
{
    itemQty = num;
}


/**
 * @brief change the unit of measurement for ingredient
 * @param unit  : The new unit of measurement
 * @author Andrew Li
 */
void RecipeItem::setItemMeasureUnit(string unit)
{
    itemMeasureUnit = unit;
}
