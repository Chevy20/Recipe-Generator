#ifndef FRIDGEITEM_H
#define FRIDGEITEM_H
#include "FoodItem.h"
#endif

class FridgeItem: public FoodItem{

    public: 
        FridgeItem(std::string unit_Type, std::string unitMeasure_Type, std::string item_name, int unit_quantity, int quantity_Threshold, char* date_Purchased, char* expiration_Date, int date_Threshold);
        ~FridgeItem();
};