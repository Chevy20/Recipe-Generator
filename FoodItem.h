#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>

class FoodItem{
    public:
        FoodItem(string item_name, int unit_quantity, string unitMeasure_Type ,string date_Purchased, string expiration_Date, string unit_Type,   int quantity_Threshold,  int date_Threshold);
        ~FoodItem();
        std::string getType ();
        std::string getName ();
        std::string getMeasureUnit();
        string getDatePurchased ();
        int getThreshold();    //quantity theshold to trigger low quantity alert
        string getExpiry();
        int   getDateThreshold();  // minimum number of days allowed between current date and expiration date to trigger expiration warning
        void incrementQty (int amount);
        void decrementQty (int amount );
        int getQuantity();

    private:
        std::string unitType;
        std::string unitMeasureType;
        std::string itemName; 
        int unitQuantity;
        int quantityThreshold; 
        int dateThreshold;
        string datePurchased;
        string expirationDate;


};
#endif