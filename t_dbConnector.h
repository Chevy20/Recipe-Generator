/*
    t_dbConnector Header File 
    This contains all the definitions for the t_dbConnector abstract class.
*/
#ifndef TDBCONNECTOR_H
#define TDBCONNECTOR_H

#include <sqlite3.h>
#include <string>
class t_dbConnector{
    public:
    virtual void connectDB() = 0;
    virtual void dropTable() = 0;    //stock_tbl 
    virtual void dropTableandRebuild() = 0;
    virtual void disconnectDB() = 0;

    protected:
        std::string dbName;     //database name
        sqlite3* db;            //Database Handle

};



#endif