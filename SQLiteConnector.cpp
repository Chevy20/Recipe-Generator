/**
 * @file SQLiteConnector.cpp
 * @author Matthew Cheverie
 * @brief SQLiteConnector program file. This file contains the implementation for the SQLiteConnector class. It inherits t_dbConnector.
 * It is used to directly create/connect to the SQLite3 database and initialize the tables.
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */   
#include "SQLiteConnector.h"
#include <iostream>
using namespace std;


/**
 * @brief Constructor - Sets the variables for this class.
 * @author Matthew Cheverie
 */
SQLiteConnector::SQLiteConnector(){
    dbName = "Freshcipes.db";
}


/**
 * @brief Destructor.
 * @author Matthew Cheverie
 */
SQLiteConnector::~SQLiteConnector(){

}


/**
 * @brief Creates a connection with the SQL database.
 * @author Matthew Cheverie
 */
void SQLiteConnector::connectDB(){
    int command = sqlite3_open(dbName.c_str(), &db);
     //code from sqllites docs for error checkking 
    if (command){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        
        sqlite3_close(db);        //needed to call destructor of the database object (sqlite3 *)
    }
    //If successful in creating the database, try to create the table
    else{
       
        char* error;
        string sql_stmt= "create table if not exists stock_tbl (itemName varchar(255), unitQuantity FLOAT, unitMeasureType varchar(255), datePurchased varchar(255), expirationDate varchar(255), unitType varchar(255), quantityThreshold FLOAT,PRIMARY KEY (itemName)) ;";
        command = sqlite3_exec(db,sql_stmt.c_str(), NULL,NULL,&error);
        
        // if the table could not be created, notify user and close database
        if(command != SQLITE_OK){
            cout << "Could not create the stock_tbl: " << error << endl;
            sqlite3_close(db);        // call destructor for the database object
           
        }
        delete error;       // delete the pointer to for the error
    }
}


/**
 * @brief Drops the stock_tbl.
 * @author Matthew Cheverie
 */
void SQLiteConnector::dropTable(){
    char* error;
    string sql_stmt = "DROP TABLE IF EXISTS stock_tbl";
    int command = sqlite3_exec(db, sql_stmt.c_str(),NULL, NULL, &error);
    if(command != SQLITE_OK){
            cout << "Could not drop the stock_tbl: " << error << endl;
        }
    delete error;       // delete the pointer to for the error

}


/**
 * @brief Drops the stock_tbl and recreates it.
 * @author Matthew Cheverie
 */
void SQLiteConnector::dropTableandRebuild(){
    char* error;
    string sql_stmt = "DROP TABLE IF EXISTS stock_tbl";
    int command = sqlite3_exec(db, sql_stmt.c_str(),NULL, NULL, &error);
    if(command != SQLITE_OK){
            cout << "Could not drop the stock_tbl: " << error << endl;
    }

    sql_stmt= "create table if not exists stock_tbl (itemName varchar(255), unitQuantity INTEGER, unitMeasureType varchar(255), datePurchased varchar(255), expirationDate varchar(255), unitType varchar(255), quantityThreshold INTEGER, PRIMARY KEY (itemName)) ;";
    command = sqlite3_exec(db,sql_stmt.c_str(), NULL,NULL,&error);
    
    // if the table could not be created, notify user and close database
    if(command != SQLITE_OK){
        cout << "Could not create the stock_tbl: " << error << endl;
        sqlite3_close(db);        // call destructor for the database object
        
    }

    delete error; 

}


/**
 * @brief Disconnects from stock_tbl.
 * @author Matthew Cheverie
 */
void SQLiteConnector::disconnectDB(){
    if(sqlite3_close(db) == SQLITE_OK){
        cout<<"Database closed successfully"<<endl;
    }
    else
        cout<<"Could not close databse"<<endl;
}


/**
 * @brief Returns the database.
 * 
 * @return The handle to the database.
 * @author Matthew Cheverie
 */
sqlite3* SQLiteConnector::getDbHandle(){
    return db;
}
