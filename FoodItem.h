/*! FoodItem Header
This file contains the definitions for the FoodItem Object
*/
#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
class FoodItem{
    //! Public Attributes
    public:
        /**
         * @brief Constructor - Sets the variables used by this class.
         */
        FoodItem();
        /**
         * @brief Constructor - Sets the variables used by this class.
         * 
         * @param item_name The name of the food item.
         * @param unit_quantity The quantity/units of the food item.
         * @param unitMeasure_Type The measurement that the food item is measured in.
         * @param date_Purchased The date that the food item was perchased (in the format YYYY/MM/DD).
         * @param expiration_Date The expiration date of the food item (in the format YYYY/MM/DD).
         * @param unit_Type Where the unit is stored.
         * @param quantity_Threshold The quantity needed to trigger a low stock alert.
         */
        FoodItem(std::string item_name, float unit_quantity, std::string unitMeasure_Type ,std::string date_Purchased, std::string expiration_Date, std::string unit_Type,   float quantity_Threshold);
        /**
         * @brief Destructor
         */
        ~FoodItem();
        /**
         * @brief Gets the storage type of the food item.
         * 
         * @return The food item's storage type.
         */
        std::string getType ();
        /**
         * @brief Gets the name of the food item.
         * 
         * @return The food item's name.
         */
        std::string getName ();
        /**
         * @brief Gets the unit of measurement of the food item.
         * 
         * @return The food item's unit of measurement.
         */
        std::string getMeasureUnit();
        /**
         * @brief Gets the date the food item was purchased on.
         * 
         * @return The purchase date.
         */
        std::string getDatePurchased ();
        /**
         * @brief Gets the quantity of food items needed to trigger a low stock alert.
         * 
         * @return The low stock quantity threshold.
         */
        float getThreshold();    //quantity theshold to trigger low quantity alert
        /**
         * @brief Gets the expiry date of the food item.
         * 
         * @return The food item's expiry date.
         */
        std::string getExpiry();
        /**
         * @brief Increments the food item's quantity by specified amount.
         * 
         * @param amount The amount to increment by.
         * 
         * @return Boolean for success.
         */
        bool incrementQty (float amount);
        /**
         * @brief Decrements the food item's quantity by specified amount.
         * 
         * @param amount The amount to decrement by.
         * 
         * @return Boolean for success. False if amount is larger than quantity.
         */
        bool decrementQty (float amount );
        /**
         * @brief Gets the amount of items in the stock.
         * 
         * @return The food item's quantity.
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
