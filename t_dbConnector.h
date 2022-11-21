/**
    t_dbConnector Header File 
    This contains all the definitions for the t_dbConnector abstract class.
*/
#ifndef TDBCONNECTOR_H
#define TDBCONNECTOR_H

#include <sqlite3.h>
#include <string>
class t_dbConnector{
    public:
    virtual void connectDB() = 0;           /**< connect to db */
    virtual void dropTable() = 0;           /**< delete stock_tbl from db */
    virtual void dropTableandRebuild() = 0; /**< reset stock_tbl from db, removing all values */
    virtual void disconnectDB() = 0;        /**< disconnect from db */

    protected:
        std::string dbName;                 /**< string: database name */
        sqlite3* db;                        /**< sqlite3*: Database Handle */

};



#endif