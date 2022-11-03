#ifndef FREEZERITEM_H
#define FREEZERITEM_H
#include "FoodItem.h"
#endif

class FreezerItem: public FoodItem{
    public: 
        FreezerItem(std::string unit_Type, std::string unitMeasure_Type, std::string item_name, int unit_quantity, int quantity_Threshold, char* date_Purchased, char* expiration_Date, int date_Threshold);
        ~FreezerItem();
};