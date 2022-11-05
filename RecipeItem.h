#ifndef RECIPEITEM_H
#define RECIPEITEM_H

#include "FoodItem.h"
class RecipeItem
{
    private:
        FoodItem item;
        int itemQty;
        std::string itemMeasureUnit;

    public:
        RecipeItem();
        RecipeItem(FoodItem fitem, int num, std::string unit);
        ~RecipeItem();
        FoodItem getItem();
        int getQuantity();
        std::string getItemMeasureUnit();
        void setItem(FoodItem fitem);
        void setQuantity(int qty);
        void setItemMeasureUnit(std::string unit);
        
};

#endif