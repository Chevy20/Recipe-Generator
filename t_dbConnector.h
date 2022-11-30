/**
 * @file t_dbConnector.h
 * @author Matthew Cheverie
 * @brief t_dbConnector header file. This contains the definitions for the Database Connector Template
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TDBCONNECTOR_H
#define TDBCONNECTOR_H

#include <sqlite3.h>
#include <string>
class t_dbConnector{
    public:
     /**
     * @brief abstract function to create and connect to database.
     * @author Matthew Cheverie 
    */
    virtual void connectDB() = 0;    

     /**
     * @brief abstract function to drop the database.
     * @author Matthew Cheverie 
    */       
    virtual void dropTable() = 0;      

     /**
     * @brief abstract function to drop table and rebuild the database.
     * @author Matthew Cheverie 
    */     
    virtual void dropTableandRebuild() = 0; 

     /**
     * @brief abstract function to deconstruct the database.
     * @author Matthew Cheverie 
    */
    virtual void disconnectDB() = 0;        

    protected:
        std::string dbName;                 /**< string: database name */
        sqlite3* db;                        /**< sqlite3*: Database Handle */

};



#endif