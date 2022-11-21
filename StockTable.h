/*
    StockTable Header File
    This file contains all the definitions for the StockTable object. It is a subclass of the t_dbTableStrategy class.
*/
#ifndef STOCKTABLE_H
#define STOCKTABLE_H

#include "t_dbTableStrategy.h"
#include <vector>
#include "FoodItem.h"
#include <string>
#include "sqlite3.h"

class StockTable : public t_dbTableStrategy{

    public:
        StockTable();                               /**< Default constructor: sets db pointer to nullptr */
        StockTable(sqlite3* _db);                   /**< Constructor: sets db pointer to input */
        ~StockTable();                              /**< Destructor: close db pointer */
        bool insert(void* item) override;           /**< add new item to db */
        bool update(void* item) override;           /**< update all values of item in db */
        bool remove(std::string itemName) override; /**< remove specific item from db */
        FoodItem select (std::string key);          /**< create a data structure for one object */
        std::vector<FoodItem> selectAll();          /**< create a vector of all items in inventory */
    private:
        sqlite3* db;                                /**< sqlite*: pointer to database */


};

#endif