#include "FoodItem.h"
#include <iostream>
using namespace std;

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

FoodItem::~FoodItem(){
   

}
string FoodItem::getType(){
    return unitType;
}

string FoodItem::getName(){
    return itemName;
}
string FoodItem::getMeasureUnit(){
    return unitMeasureType;
}
string FoodItem::getDatePurchased(){
    return datePurchased;
}
int FoodItem::getThreshold(){
    return quantityThreshold;
}
string FoodItem::getExpiry(){
    return expirationDate;
}
int FoodItem::getDateThreshold(){
    return dateThreshold;
}

int FoodItem::getQuantity(){
    return unitQuantity;
}
void FoodItem::incrementQty (int amount){
    unitQuantity = unitQuantity + amount;
}
void FoodItem::decrementQty (int amount ){
    if(unitQuantity - amount < 0)
        cout << "Invalid use of items. Not enough in stock" <<endl;
    else{
        unitQuantity = unitQuantity - amount;
    }
}
