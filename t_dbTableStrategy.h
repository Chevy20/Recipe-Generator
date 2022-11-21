/**
    t_dbTableStrategy header file 
    This file contains all the definitions for the t_dbTable abstract class.
*/
#ifndef TDBTABLESTRATEGY_H
#define TDBTABLESTRATEGY_H

#include <string>
#include "sqlite3.h"
class t_dbTableStrategy{
    public:
    
    virtual bool insert(void* item) = 0;            /**< deference as either FoodItem or user or recipeItem based on currentDB context */
    virtual bool update(void* item) = 0;            /**< deference as either FoodItem or user or recipeItem based on currentDB context */
    virtual bool remove(std::string itemName) = 0;  /**< remove a specific item from stock */

    protected:
    sqlite3* db;    //database handle               /**< sqlite3*: pointer to db */

};
#endif