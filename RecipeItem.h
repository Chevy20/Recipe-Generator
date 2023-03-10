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
        std::string item;               /**< string: name of the foodItem */
        float itemQty;               /**< float: The numerical quantity of ingredients in recipe */
        std::string itemMeasureUnit; /**< string: The unit of measurement of ingredient in recipe */

    public:
        /**
         * @brief construct the recipe ingredient
         * @author Andrew Li
         */
        RecipeItem();
        /**
         * @brief construct the recipe ingredient
         * @param fitem : the string of the name of food item 
         * @param num   : the quantity in numeric value
         * @param unit  : the string of the unit of the quantity of the ingredient
         * @author Andrew Li
         * @author Kanishk Mishra
         */
        RecipeItem(std::string fitem, float num, std::string unit);
        /**
         * @brief destroy the recipe ingredient
         * @author Andrew Li
         */
        ~RecipeItem();
        /**
         * @brief get the name of the ingredient
         * @return the name of the ingredient
         * @author Andrew Li
         */
        std::string getItem();
        /**
         * @brief access the numeric quantity of ingredient
         * @return the number of items
         * @author Andrew Li
         */
        float getQuantity();
        /**
         * @brief access the measurement of the ingredient
         * @return string of the unit of measurement
         * @author Andrew Li
         */
        std::string getItemMeasureUnit();
        /**
         * @brief setter method for the name of item
         * @param fitem : the new name of this ingredient
         * @author Andrew Li
         */
        void setItem(std::string fItem);
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