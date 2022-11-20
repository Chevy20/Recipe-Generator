#ifndef RECIPEITEM_H
#define RECIPEITEM_H

#include "FoodItem.h"
/**
 * @brief This class stores information about a specific ingredient in a specific recipe
 * @author Kanishk Mishra
 * @author Andrew Li
 */
class RecipeItem
{
    private:
        /**
         * FoodItem
         * The original ingredient from the inventory
         */
        FoodItem item;
        /**
         * float
         * The numerical quantity of ingredients in recipe
         */
        float itemQty;
        /**
         * string
         * The unit of measurement of ingredient in recipe
         */
        std::string itemMeasureUnit;

    public:
        /**
         * @brief construct the recipe ingredient
         * @author Andrew Li
         */
        RecipeItem();
        /**
         * @brief construct the recipe ingredient
         * @param fitem : the FoodItem from our inventory in recipe
         * @param num   : the quantity in numeric value
         * @param unit  : the string of the unit of the quantity of the ingredient
         * @author Andrew Li
         * @author Kanishk Mishra
         */
        RecipeItem(FoodItem fitem, float num, std::string unit);
        /**
         * @brief destroy the recipe ingredient
         * @author Andrew Li
         */
        ~RecipeItem();
        /**
         * @brief access the original ingredient in inventory
         * @return the original FoodItem
         * @author Andrew Li
         */
        FoodItem getItem();
        /**
         * @brief access the numeric quantity of ingredient
         * @return the number of items
         * @author Andrew Li
         */
        int getQuantity();
        /**
         * @brief access the measurement of the ingredient
         * @return string of the unit of measurement
         * @author Andrew Li
         */
        std::string getItemMeasureUnit();
        /**
         * @brief change the original ingredient in inventory
         * @param fitem : the new FoodItem from inventory
         * @author Andrew Li
         */
        void setItem(FoodItem fItem);
        /**
         * @brief change the numerical quantity in recipe
         * @param qty   : float for the quantity of ingredients
         * @author Andrew Li
         * @author Kanishk Mishra
         */
        void setQuantity(float qty);
        /**
         * @brief change the unit of measurement for ingredient
         * @param unit  : The new unit of measurement
         * @author Andrew Li
         */
        void setItemMeasureUnit(std::string unit);
        
};

#endif