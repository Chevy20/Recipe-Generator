/**
 * @file StockTable.h
 * @author Matthew Cheverie
 * @brief StockTable header file. This file contains the defintions for the StockTable class. It inherits t_dbTableStrategy.
 * It is used to directly interface with the SQLite3 database
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
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
        /**
         * @brief Constructor - Sets teh variables for this class.
         * @author Matthew Cheverie
         */
        StockTable();
		/**
         * @brief Constructor - Sets teh variables for this class.
         * 
         * @param _db The database to set.
         * @author Matthew Cheverie
         */
        StockTable(sqlite3* _db);
		/**
         * @brief Destructor - Closes the database.
         * @author Matthew Cheverie
         */
        ~StockTable();
        /**
         * @brief Inserts a food item into the database.
         * 
         * @param item A void pointer to a food item to insert.
         * 
         * @return Boolean of success.
         * @author Matthew Cheverie
         */
        bool insert(void* item) override;
        /**
         * @brief Updates a food item in the database.
         * 
         * @param item A void pointer to a food item to update.
         * 
         * @return Boolean of success.
         * @author Matthew Cheverie
         */
        bool update(void* item) override;
        /**
         * @brief Removes a food item from the database.
         * 
         * @param item The name of the food item to remove.
         * 
         * @return Boolean of success.
         * @author Matthew Cheverie
		 */
		bool remove(std::string itemName) override;
        /**
         * @brief Gets the food item data from the database that has the same name as specified.
         * 
         * @param key The item name to query for.
         * 
         * @return The food item.
         * @author Matthew Cheverie
         */
        FoodItem select (std::string key);
        /**
         * @brief Gets the food item data of all items from the database.
         * 
         * @return The list of food items.
         * @author Matthew Cheverie
         */
        std::vector<FoodItem> selectAll();
    private:
        sqlite3* db;	/**< sqlite*: pointer to database */


};

#endif
