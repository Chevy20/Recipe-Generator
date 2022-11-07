#ifndef RECIPEITEM_H
#define RECIPEITEM_H

#include "FoodItem.h"
class RecipeItem
{
    private:
        FoodItem item;
        float itemQty;
        std::string itemMeasureUnit;

    public:
        RecipeItem();
        RecipeItem(FoodItem fitem, float num, std::string unit);
        ~RecipeItem();
        FoodItem getItem();
        int getQuantity();
        std::string getItemMeasureUnit();
        void setItem(FoodItem fitem);
        void setQuantity(float qty);
        void setItemMeasureUnit(std::string unit);
        
};

#endif