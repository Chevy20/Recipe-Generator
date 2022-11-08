#include "SQLiteConnector.h"
#include <iostream>
using namespace std;

/*
Function:
Description:
Parameters:
Return:
*/
SQLiteConnector::SQLiteConnector(){
    dbName = "FreshRecipes.db";
}

/*
Function:
Description:
Parameters:
Return:
*/
SQLiteConnector::~SQLiteConnector(){

}

/*
Function:
Description:
Parameters:
Return:
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
Function:
Description:
Parameters:
Return:
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
Function:
Description:
Parameters:
Return:
*/
void SQLiteConnector::dropTableandRebuild(){
    char* error;
    string sql_stmt = "DROP TABLE IF EXISTS stock_tbl";
    int command = sqlite3_exec(db, sql_stmt.c_str(),NULL, NULL, &error);
    if(command != SQLITE_OK){
            cout << "Could not drop the stock_tbl: " << error << endl;
    }

    sql_stmt= "create table if not exists stock_tbl (itemName varchar(255), unitQuantity INTEGER, unitMeasureType varchar(255), datePurchased varchar(255), expirationDate varchar(255), unitType varchar(255), quantityThreshold INTEGER, dateThreshold INTEGER, PRIMARY KEY (itemName)) ;";
    command = sqlite3_exec(db,sql_stmt.c_str(), NULL,NULL,&error);
    
    // if the table could not be created, notify user and close database
    if(command != SQLITE_OK){
        cout << "Could not create the stock_tbl: " << error << endl;
        sqlite3_close(db);        // call destructor for the database object
        
    }

    delete error; 

}

/*
Function:
Description:
Parameters:
Return:
*/
void SQLiteConnector::disconnectDB(){
    if(sqlite3_close(db) == SQLITE_OK){
        cout<<"Database closed successfully"<<endl;
    }
    else
        cout<<"Could not close databse"<<endl;
}

/*
Function:
Description:
Parameters:
Return:
*/
sqlite3* SQLiteConnector::getDbHandle(){
    return db;
}
