#include <iostream>
#include "RecipeItem.h"

using namespace std;
RecipeItem::RecipeItem()
{
    //default
}
RecipeItem::RecipeItem(FoodItem fitem, float num, string unit)
{
    item = fitem;
    itemQty = num;
    itemMeasureUnit = unit;
}
RecipeItem::~RecipeItem()
{

}
FoodItem RecipeItem::getItem()
{
    return item;
}
float RecipeItem::getQuantity()
{
    return itemQty;
}
string RecipeItem::getItemMeasureUnit()
{
    return itemMeasureUnit;
}
void RecipeItem::setItem(FoodItem fItem)
{
    item = fItem;
}
void RecipeItem::setQuantity(float num)
{
    itemQty = num;
}
void RecipeItem::setItemMeasureUnit(string unit)
{
    itemMeasureUnit = unit;
}