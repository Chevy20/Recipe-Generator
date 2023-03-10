/**
 * @file t_dbTableStrategy.h
 * @author Matthew Cheverie
 * @brief t_dbTableStrategy header file. This contains the definitions for the Database Table Strategy template
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TDBTABLESTRATEGY_H
#define TDBTABLESTRATEGY_H

#include <string>
#include "sqlite3.h"
class t_dbTableStrategy{
    public:
    /**
     * @brief abstract function to insert into the database.
     * @param item void pointer that will be cast to the table we are looking at
     * @author Matthew Cheverie 
    */
    virtual bool insert(void* item) = 0;   
    
    /**
     * @brief abstract function to update an entry in the sql database
     * @param item void pointer that will be cast to the table we are looking at
     * @author Matthew Cheverie 
    */
    virtual bool update(void* item) = 0;    

    /**
     * @brief abstract function to remove something from the database
     * @param itemName string to represent the name of the item to be removed
     * @author Matthew Cheverie 
    */
    virtual bool remove(std::string itemName) = 0;  

    protected:
    sqlite3* db;    /**< sqlite3*: pointer to db */

};
#endif