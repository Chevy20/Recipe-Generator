/* FoodItem Implementation file
    This file contains the implementation for all methods of the FoodItem Class
*/
#include "FoodItem.h"
#include <iostream>
using namespace std;

/*
Function: Default FoodItem Constructor
Description: The default constructor for the FoodItem object. Sets all string attributes to "" and all integer values to 0
Parameters: nothing
Return: FoodItem object
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

/*
Function: FoodItem constructor
Description: The constructor for the food item object
Parameters: string item_name: the name of the food item, int unit_quantity: the units of food items, string unitMeasure_Type: the type of unit the quantity is measured in,
string date_Purchased: purchase date in form YYYY/MM/DD, string expiration_Date: expiration date in form YYYY/MM/DD, string unit_Type: where the unit is stored, 
int quantity_Threshold: the amount needed to trigger low stock alert, int date_Threshold: the number of days from the expiration date that an expiry warning will be triggered
Return: FoodItem object
*/
FoodItem::FoodItem(string item_name, float unit_quantity, string unitMeasure_Type ,string date_Purchased, string expiration_Date, string unit_Type,   float quantity_Threshold){
    unitType = unit_Type;
    unitMeasureType = unitMeasure_Type;
    itemName = item_name;
    unitQuantity = unit_quantity;
    quantityThreshold = quantity_Threshold;
    datePurchased = date_Purchased;
    expirationDate = expiration_Date;
    
}

/*
Function: ~FoodItem()
Description: The default destructor for the FoodItem object
Parameters: none
Return: none
*/
FoodItem::~FoodItem(){
   

}
/*
Function: getType()
Description: Gets the storage type of the food
Parameters: none
Return: string representing the storage type
*/
string FoodItem::getType(){
    return unitType;
}

/*
Function: getName()
Description: Gets the name of the food item
Parameters: none
Return: string representing the name of the food
*/
string FoodItem::getName(){
    return itemName;
}

/*
Function: getMeasureUnit()
Description: Gets the unit of measurement for the food
Parameters: none
Return: string representing the measurement unit of the food
*/
string FoodItem::getMeasureUnit(){
    return unitMeasureType;
}

/*
Function: getDatePurchased()
Description: Gets the date the item was purchased on
Parameters: none
Return: string representing the purchase date
*/
string FoodItem::getDatePurchased(){
    return datePurchased;
}

/*
Function: getThreshold
Description: Gets the number of measurement units where a low stock alert will be sent
Parameters: none
Return: String representing the quantity threshold
*/
float FoodItem::getThreshold(){
    return quantityThreshold;
}

/*
Function: getExpiry()
Description: Gets the expiry date of the  food
Parameters: none
Return: string representing the expiry date
*/
string FoodItem::getExpiry(){
    return expirationDate;
}


/*
Function: getQuantity()
Description: Gives the amount of items in the stock
Parameters: none
Return: integer representing the amount of food in stock 
*/
float FoodItem::getQuantity(){
    return unitQuantity;
}

/*
Function: incrementQty()
Description: Increments quantity specified by passed in amount
Parameters: int amount: amount to increment by 
Return: true if able to increment
*/
bool FoodItem::incrementQty (float amount){

    unitQuantity = unitQuantity + amount;
    return true;

}

/*
Function: decrementQty()
Description: Decreases qty by amount passed in, but not below 0
Parameters: int amount: amount to decrement by
Return: true if able to decrement, false if not
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
