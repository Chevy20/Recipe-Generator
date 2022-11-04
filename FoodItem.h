#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>

class FoodItem{
    public:
        ~FoodItem();
        virtual std::string getType () = 0;
        virtual std::string getName () = 0;
        virtual std::string getMeasureUnit() = 0;
        virtual char* getDatePurchased () = 0;
        virtual int getThreshold() = 0;     //quantity theshold to trigger low quantity alert
        virtual char* getExpiry() = 0;
        virtual int   getDateThreshold() = 0;   // minimum number of days allowed between current date and expiration date to trigger expiration warning
        virtual void incrementQty (int amount) = 0;
        virtual void decrementQty (int amount ) = 0;

    protected:
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