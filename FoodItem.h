/**
 * @file FoodItem.h
 * @author Matthew Cheverie
 * @brief FoodItem header file. Contains the defininitions for the FoodItem Class.
 * Used to represent records in database.
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
class FoodItem{
    //! Public Attributes
    public:
        /**
         * @brief Constructor - Sets the variables used by this class.
         * @author Matthew Cheverie
         */
        FoodItem();
        /**
         * @brief Constructor - Sets the variables used by this class.
         * 
         * 
         * @param item_name The name of the food item.
         * @param unit_quantity The quantity/units of the food item.
         * @param unitMeasure_Type The measurement that the food item is measured in.
         * @param date_Purchased The date that the food item was perchased (in the format YYYY/MM/DD).
         * @param expiration_Date The expiration date of the food item (in the format YYYY/MM/DD).
         * @param unit_Type Where the unit is stored.
         * @param quantity_Threshold The quantity needed to trigger a low stock alert.
         * @author Matthew Cheverie
         */
        FoodItem(std::string item_name, float unit_quantity, std::string unitMeasure_Type ,std::string date_Purchased, std::string expiration_Date, std::string unit_Type,   float quantity_Threshold);
        /**
         * @brief Destructor
         * @author Matthew Cheverie
         */
        ~FoodItem();
        /**
         * @brief Gets the storage type of the food item.
         * 
         * @return The food item's storage type.
         * @author Matthew Cheverie
         */
        std::string getType ();
        /**
         * @brief Gets the name of the food item.
         * 
         * @return The food item's name.
         * @author Matthew Cheverie
         */
        std::string getName ();
        /**
         * @brief Gets the unit of measurement of the food item.
         * 
         * @return The food item's unit of measurement.
         * @author Matthew Cheverie
         */
        std::string getMeasureUnit();
        /**
         * @brief Gets the date the food item was purchased on.
         * 
         * @return The purchase date.
         * @author Matthew Cheverie
         */
        std::string getDatePurchased ();
        /**
         * @brief Gets the quantity of food items needed to trigger a low stock alert.
         * 
         * @return The low stock quantity threshold.
         * @author Matthew Cheverie
         */
        float getThreshold();    //quantity theshold to trigger low quantity alert
        /**
         * @brief Gets the expiry date of the food item.
         * 
         * @return The food item's expiry date.
         * @author Matthew Cheverie
         */
        std::string getExpiry();
        /**
         * @brief Increments the food item's quantity by specified amount.
         * 
         * @param amount The amount to increment by.
         * 
         * @return Boolean for success.
         * @author Matthew Cheverie
         */
        bool incrementQty (float amount);
        /**
         * @brief Decrements the food item's quantity by specified amount.
         * 
         * @param amount The amount to decrement by.
         * 
         * @return Boolean for success. False if amount is larger than quantity.
         * @author Matthew Cheverie
         */
        bool decrementQty (float amount );
        /**
         * @brief Gets the amount of items in the stock.
         * 
         * @return The food item's quantity.
         * @author Matthew Cheverie
         */
        float getQuantity();

    private:
        std::string unitType;
        std::string unitMeasureType;
        std::string itemName; 
        float unitQuantity;
        float quantityThreshold; 
        std::string datePurchased;
        std::string expirationDate;


};

#endif
