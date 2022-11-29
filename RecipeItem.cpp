#include <iostream>
#include "RecipeItem.h"

using namespace std;
RecipeItem::RecipeItem()
{
    //default
}
RecipeItem::RecipeItem(string fitem, float num, string unit)
{
    item = fitem;
    itemQty = num;
    itemMeasureUnit = unit;
}
RecipeItem::~RecipeItem()
{

}
string RecipeItem::getItem()
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
void RecipeItem::setItem(string fItem)
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