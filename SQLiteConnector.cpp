#include "SQLiteConnector.h"
#include <iostream>
using namespace std;

/*
Function: SQLiteConnector Constructor
Description: constructs an SQLiteConnector object that extends the t_dbConnector class
Parameters: none
Return: SQLite Connector object
*/
SQLiteConnector::SQLiteConnector(){
    dbName = "Freshcipes.db";
}

/*
Function: SQLiteConnector Destructor
Description: Destructor for the SQLiteConnector Object
Parameters: none
Return: none
*/
SQLiteConnector::~SQLiteConnector(){

}

/*
Function: connectDB()
Description: Function to create a connection with the SQL database
Parameters: none
Return: none
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
        string sql_stmt= "create table if not exists stock_tbl (itemName varchar(255), unitQuantity INTEGER, unitMeasureType varchar(255), datePurchased varchar(255), expirationDate varchar(255), unitType varchar(255), quantityThreshold INTEGER, dateThreshold INTEGER, PRIMARY KEY (itemName)) ;";
        command = sqlite3_exec(db,sql_stmt.c_str(), NULL,NULL,&error);
        
        // if the table could not be created, notify user and close database
        if(command != SQLITE_OK){
            cout << "Could not create the stock_tbl: " << error << endl;
            sqlite3_close(db);        // call destructor for the database object
           
        }
        delete error;       // delete the pointer to for the error
    }
}


/*
Function: dropTable()
Description: Function to drop stock_tbl if needed
Parameters: none
Return: none
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

/*
Function: dropTableandRebuild
Description: Function to drop a table and recreate it if needed
Parameters:none 
Return:none
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

/*
Function: discconectDB()
Description: Function to disconnect from the SQLDB
Parameters:none
Return: none
*/
void SQLiteConnector::disconnectDB(){
    if(sqlite3_close(db) == SQLITE_OK){
        cout<<"Database closed successfully"<<endl;
    }
    else
        cout<<"Could not close databse"<<endl;
}

/*
Function: getDbHandle()
Description: Getter Function for the database handle
Parameters: 
Return: sqlite3* object representing the handle to the database
*/
sqlite3* SQLiteConnector::getDbHandle(){
    return db;
}
