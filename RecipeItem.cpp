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
int RecipeItem::getQuantity()
{
    return itemQty;
}
string RecipeItem::getItemMeasureUnit()
{
    return itemMeasureUnit;
}
void RecipeItem::setItem(FoodItem fitem)
{
    item = fitem;
}
void RecipeItem::setQuantity(float num)
{
    itemQty = num;
}
void RecipeItem::setItemMeasureUnit(string unit)
{
    itemMeasureUnit = unit;
}