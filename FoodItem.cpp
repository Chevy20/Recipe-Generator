/* FoodItem Implementation file
    This file contains the implementation for all methods of the FoodItem Class
*/
#include "FoodItem.h"
#include <iostream>
using namespace std;

/*
Function: Default Constructor
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
    dateThreshold = 0;
    datePurchased = "";
    expirationDate = "";
}

/*
Function: FoodItem Constructor
Description:
Parameters:
Return:
*/
FoodItem::FoodItem(string item_name, int unit_quantity, string unitMeasure_Type ,string date_Purchased, string expiration_Date, string unit_Type,   int quantity_Threshold,  int date_Threshold){
    unitType = unit_Type;
    unitMeasureType = unitMeasure_Type;
    itemName = item_name;
    unitQuantity = unit_quantity;
    quantityThreshold = quantity_Threshold;
    dateThreshold = date_Threshold;
    datePurchased = date_Purchased;
    expirationDate = expiration_Date;
    
}

/*
Function:
Description:
Parameters:
Return:
*/
FoodItem::~FoodItem(){
   

}
/*
Function:
Description:
Parameters:
Return:
*/
string FoodItem::getType(){
    return unitType;
}

/*
Function:
Description:
Parameters:
Return:
*/
string FoodItem::getName(){
    return itemName;
}

/*
Function:
Description:
Parameters:
Return:
*/
string FoodItem::getMeasureUnit(){
    return unitMeasureType;
}

/*
Function:
Description:
Parameters:
Return:
*/
string FoodItem::getDatePurchased(){
    return datePurchased;
}

/*
Function:
Description:
Parameters:
Return:
*/
int FoodItem::getThreshold(){
    return quantityThreshold;
}

/*
Function:
Description:
Parameters:
Return:
*/
string FoodItem::getExpiry(){
    return expirationDate;
}

/*
Function:
Description:
Parameters:
Return:
*/
int FoodItem::getDateThreshold(){
    return dateThreshold;
}

/*
Function:
Description:
Parameters:
Return:
*/
int FoodItem::getQuantity(){
    return unitQuantity;
}

/*
Function:
Description:
Parameters:
Return:
*/
bool FoodItem::incrementQty (int amount){

    unitQuantity = unitQuantity + amount;
    return true;

}

/*
Function:
Description:
Parameters:
Return:
*/
bool FoodItem::decrementQty (int amount ){
    if(unitQuantity - amount < 0){
        cout << "Invalid use of items. Not enough in stock" <<endl;
        return false;
    }
    else{
        unitQuantity = unitQuantity - amount;
    }
    return true;
}
