#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>

class FoodItem{
    public:
        FoodItem(std::string unit_Type, std::string unitMeasure_Type, std::string item_name, int unit_quantity, int quantity_Threshold, char* date_Purchased, char* expiration_Date, int date_Threshold);
        ~FoodItem();
        std::string getType ();
        std::string getName ();
        std::string getMeasureUnit();
        char* getDatePurchased ();
        int getThreshold();     //quantity theshold to trigger low quantity alert
        char* getExpiry();
        int   getDateThreshold();   // minimum number of days allowed between current date and expiration date to trigger expiration warning
        void incrementQty (int amount);
        void decrementQty (int amount );
    private:
        std::string unitType;
        std::string unitMeasureType;
        std::string itemName; 
        int unitQuantity;
        int quantityThreshold; 
        int dateThreshold;
        char* datePurchased;
        char* expirationDate;


};
#endif