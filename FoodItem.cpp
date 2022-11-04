#include "FoodItem.h"

using namespace std;
FoodItem::FoodItem(string unit_Type, string unitMeasure_Type, string item_name, int unit_quantity, int quantity_Threshold, char* date_Purchased, char* expiration_Date, int date_Threshold){
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
char* FoodItem::getDatePurchased(){
    return datePurchased;
}
int FoodItem::getThreshold(){
    return quantityThreshold;
}
char* FoodItem::getExpiry(){
    return expirationDate;
}
int FoodItem::getDateThreshold(){
    return dateThreshold;
}
void FoodItem::incrementQty (int amount){
    unitQuantity = unitQuantity + amount;
}
void FoodItem::decrementQty (int amount ){
    unitQuantity = unitQuantity - amount;
}
