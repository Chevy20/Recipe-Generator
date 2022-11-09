/*! FoodItem Header
This file contains the definitions for the FoodItem Object
*/
#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
class FoodItem{
    /**< Public Attributes*/
    public:
        FoodItem();                         /**< Default constructor*/
        FoodItem(std::string item_name, int unit_quantity, std::string unitMeasure_Type ,std::string date_Purchased, std::string expiration_Date, std::string unit_Type,   int quantity_Threshold,  int date_Threshold);    //Constructor
        ~FoodItem();                        /**< Destructor*/
        std::string getType ();             /**< getter for storage type*/
        std::string getName ();             /**< getter for name of food item*/
        std::string getMeasureUnit();       /**< getter for the measurement unit*/
        std::string getDatePurchased ();    /**< getter for purchase date*/
        int getThreshold();                 /**< getter for quantity threshold*/
        std::string getExpiry();            /**< getter for expiry date*/
        int   getDateThreshold();           /**< getter for date threshold*/
        bool incrementQty (int amount);     /**< function to increase quantity*/
        bool decrementQty (int amount );    /**< function to decrease quantity, but not below zero*/
        int getQuantity();                  /**< getter for remaining quantity*/

    /**< Private Attributes*/
    private:
        std::string unitType;               /**< storage type for object*/
        std::string unitMeasureType;        /**< measurement type for object*/
        std::string itemName;               /**< name of food */
        int unitQuantity;                   /**< numerical amount of food, measured in units specified by user*/
        int quantityThreshold;              /**< threshold in which a low quantity alert is triggered*/
        int dateThreshold;                  /**< threshold in which an expiration alert is triggered*/
        std::string datePurchased;          /**< date the food was purchased YYYY/MM/DD*/
        std::string expirationDate;         /**< expiration date of the food YYYY/MM/DD*/


};
#endif