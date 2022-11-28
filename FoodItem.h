/*! FoodItem Header
This file contains the definitions for the FoodItem Object
*/
#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
class FoodItem{
    /**< Public Attributes*/
    public:
        FoodItem();
        FoodItem(std::string item_name, float unit_quantity, std::string unitMeasure_Type ,std::string date_Purchased, std::string expiration_Date, std::string unit_Type,   float quantity_Threshold);
        ~FoodItem();
        std::string getType ();
        std::string getName ();
        std::string getMeasureUnit();
        std::string getDatePurchased ();
        float getThreshold();    //quantity theshold to trigger low quantity alert
        std::string getExpiry();
        bool incrementQty (float amount);
        bool decrementQty (float amount );
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