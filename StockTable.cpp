/**
 * @file StockTable.h
 * @author Matthew Cheverie
 * @brief StockTable program. This file contains the implementations for the functions StockTable class. It inherits t_dbTableStrategy.
 * It is used to directly interface with the SQLite3 database
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "sqlite3.h"
#include "StockTable.h"
#include <iostream>
using namespace std;


/**
 * @brief Constructor - Sets teh variables for this class.
 * @author Matthew Cheverie
 */
StockTable::StockTable(){
    db = nullptr;
}


/**
 * @brief Constructor - Sets teh variables for this class.
 * 
 * @param _db The database to set.
 * @author Matthew Cheverie
 */
StockTable::StockTable(sqlite3* _db){
    db = _db;
}


/**
 * @brief Destructor - Closes the database.
 * @author Matthew Cheverie
 */
StockTable::~StockTable(){
    sqlite3_close(db); 
}


/**
 * @brief Gets the food item data from the database that has the same name as specified.
 * 
 * @param key The item name to query for.
 * 
 * @return The food item.
 * @author Matthew Cheverie
 */
FoodItem StockTable::select (string key){
    FoodItem* result = new FoodItem();
    sqlite3_stmt *stmt;         //pointer that will comtain the sql statment object
    string sql_stmt = "select * from stock_tbl where itemName = '"+key+"'";  // the sql query
    
    //use prepare to start the query, if it returns -1, there is an error. Pass result by ref to stmt
    if(sqlite3_prepare_v2(this->db,sql_stmt.c_str(),-1,&stmt,NULL)){
        cout << "Error querying the stock for "+key+""<< endl;
        
        
    }
    // if no error
    else{

        //step through the sql_stmt object until it returns done
        while(sqlite3_step(stmt) != SQLITE_DONE){
            if (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))) =="") {
                return FoodItem();
            }
            
            string itemName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))); 
            int quantity = stoi(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))));   
            string MeasureType = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));   
            string datePurchased = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))); 
            string expDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));   
            string type = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))); 
            int quanThresh = stoi(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)))); 
            result = new FoodItem(itemName,quantity,MeasureType,datePurchased,expDate,type,quanThresh);
        }
    }
    //finalize will call the destructor of stmt
    int finalize = sqlite3_finalize(stmt);
    return *result;
}


/**
 * @brief Gets the food item data of all items from the database.
 * 
 * @return The list of food items.
 * @author Matthew Cheverie
 */
std::vector<FoodItem> StockTable::selectAll(){
    vector<FoodItem> result;
    sqlite3_stmt *stmt;         //pointer that will comtain the sql statment object
    string sql_stmt = "select * from stock_tbl";  // the sql query
    
    //use prepare to start the query, if it returns -1, there is an error. Pass result by ref to stmt
    if(sqlite3_prepare_v2(this->db,sql_stmt.c_str(),-1,&stmt,NULL)){
        cout << "Error querying the stock for all entries"<< endl;
        
    }
    // if no error
    else{

        //step through the sql_stmt object until it returns done
        while(sqlite3_step(stmt) != SQLITE_DONE){
            string itemName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))); 
            int quantity = stoi(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))));   
            string MeasureType = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));   
            string datePurchased = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))); 
            string expDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));   
            string type = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))); 
            int quanThresh = stoi(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))));  
            FoodItem add =  FoodItem(itemName,quantity,MeasureType,datePurchased,expDate,type,quanThresh);
            result.push_back(add);
        }
    }
    //finalize will call the destructor of stmt
    int finalize = sqlite3_finalize(stmt);
    return result;

}


/**
 * @brief Inserts a food item into the database.
 * 
 * @param item A void pointer to a food item to insert.
 * 
 * @return Boolean of success.
 * @author Matthew Cheverie
 */
bool StockTable::insert(void* item){
    
    // Chose void pointer method in case we have any other tables 
    FoodItem record = *(FoodItem*)item;
    string itemName = record.getName();
    string quantity = std::to_string(record.getQuantity());
    string measureType = record.getMeasureUnit();
    string purchaseDate = record.getDatePurchased();
    string expirationDate = record.getExpiry();
    string unitType = record.getType();
    string quanThresh = std::to_string(record.getThreshold());
    char* error;
    string sql_stmt = "INSERT INTO stock_tbl (itemName, unitQuantity, unitMeasureType, datePurchased, expirationDate, unitType, quantityThreshold) VALUES ('"+itemName+"', "+quantity+", '"+measureType+"', '"+purchaseDate+"', '"+expirationDate+"', '"+unitType+"', "+quanThresh+")";
    int command = sqlite3_exec(this->db, sql_stmt.c_str(),NULL, NULL, &error);
    if(command != SQLITE_OK){
            cout << "Could not insert record into stock_tbl: " << error << endl;
            return false;
    }
    delete error;
    return true;
}


/**
 * @brief Updates a food item in the database.
 * 
 * @param item A void pointer to a food item to update.
 * 
 * @return Boolean of success.
 * @author Matthew Cheverie
 */
bool StockTable::update(void* item){
    FoodItem record = *(FoodItem*)item;
    string itemName = record.getName();
    string quantity = std::to_string(record.getQuantity());
    string measureType = record.getMeasureUnit();
    string purchaseDate = record.getDatePurchased();
    string expirationDate = record.getExpiry();
    string unitType = record.getType();
    string quanThresh = std::to_string(record.getThreshold());
   
    char* error;
    string sql_stmt = "UPDATE stock_tbl SET itemName ='"+itemName+"', unitQuantity = "+quantity+", unitMeasureType = '"+measureType+"', datePurchased= '"+purchaseDate+"', expirationDate= '"+expirationDate+"', unitType = '"+unitType+"', quantityThreshold= "+quanThresh+" WHERE itemName = '"+itemName+"'";
    int command = sqlite3_exec(this->db, sql_stmt.c_str(),NULL, NULL, &error);
    if(command != SQLITE_OK){
            cout << "Could not update record in stock_tbl: " << error << endl;
            return false;
    }
    delete error;
    return true;
}


/**
 * @brief Removes a food item from the database.
 * 
 * @param item The name of the food item to remove.
 * 
 * @return Boolean of success.
 * @author Matthew Cheverie
 */
bool StockTable::remove(std::string itemName){
    
    char* error;
    string sql_stmt = "DELETE from stock_tbl where itemName = '"+itemName+"'";
    int command = sqlite3_exec(this->db, sql_stmt.c_str(),NULL, NULL, &error);
    if(command != SQLITE_OK){
            cout << "Could not delete record in stock_tbl: " << error << endl;
            return false;
    }
    delete error;
    return true;
}
