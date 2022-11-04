#ifndef TDBTABLESTRATEGY_H
#define TDBTABLESTRATEGY_H

#include <string>
class t_dbTableStrategy{
    public:
    virtual bool insert(void* item) = 0; // deference as either FoodItem or recipeItem based on currentDB context 
    virtual bool update(std::string itemName) = 0;
    virtual bool remove(std::string itemName) = 0;


};
#endif