/* FoodItem Implementation file
    This file contains the implementation for all methods of the FoodItem Class
*/
#include "FoodItem.h"
#include <iostream>
using namespace std;


/**
 * @brief Constructor - Sets the variables used by this class.
 */
FoodItem::FoodItem(){
    unitType = "";
    unitMeasureType = "";
    itemName = "";
    unitQuantity = 0;
    quantityThreshold = 0;
    datePurchased = "";
    expirationDate = "";
}


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
FoodItem::FoodItem(string item_name, float unit_quantity, string unitMeasure_Type ,string date_Purchased, string expiration_Date, string unit_Type, float quantity_Threshold){
    unitType = unit_Type;
    unitMeasureType = unitMeasure_Type;
    itemName = item_name;
    unitQuantity = unit_quantity;
    quantityThreshold = quantity_Threshold;
    datePurchased = date_Purchased;
    expirationDate = expiration_Date;
    
}


/**
 * @brief Destructor
 */
FoodItem::~FoodItem(){

}


/**
 * @brief Gets the storage type of the food item.
 * 
 * @return The food item's storage type.
 */
string FoodItem::getType(){
    return unitType;
}


/**
 * @brief Gets the name of the food item.
 * 
 * @return The food item's name.
 */
string FoodItem::getName(){
    return itemName;
}


/**
 * @brief Gets the unit of measurement of the food item.
 * 
 * @return The food item's unit of measurement.
 */
string FoodItem::getMeasureUnit(){
    return unitMeasureType;
}


/**
 * @brief Gets the date the food item was purchased on.
 * 
 * @return The purchase date.
 */
string FoodItem::getDatePurchased(){
    return datePurchased;
}


/**
 * @brief Gets the quantity of food items needed to trigger a low stock alert.
 * 
 * @return The low stock quantity threshold.
 */
float FoodItem::getThreshold(){
    return quantityThreshold;
}


/**
 * @brief Gets the expiry date of the food item.
 * 
 * @return The food item's expiry date.
 */
string FoodItem::getExpiry(){
    return expirationDate;
}


/**
 * @brief Gets the amount of items in the stock.
 * 
 * @return The food item's quantity.
 */
float FoodItem::getQuantity(){
    return unitQuantity;
}


/**
 * @brief Increments the food item's quantity by specified amount.
 * 
 * @param amount The amount to increment by.
 * 
 * @return Boolean for success.
 */
bool FoodItem::incrementQty (float amount){

    unitQuantity = unitQuantity + amount;
    return true;

}


/**
 * @brief Decrements the food item's quantity by specified amount.
 * 
 * @param amount The amount to decrement by.
 * 
 * @return Boolean for success. False if amount is larger than quantity.
 */
bool FoodItem::decrementQty (float amount ){
    if(unitQuantity - amount < 0){
        cout << "Invalid use of items. Not enough in stock" <<endl;
        return false;
    }
    else{
        unitQuantity = unitQuantity - amount;
    }
    return true;
}
