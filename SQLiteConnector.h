/**
    SQLiteConnector Object
    This headed contains the definitions for the SQLiteConnector object. It is a subclass of t_dbConnector
*/
#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include "t_dbConnector.h"

class SQLiteConnector : public t_dbConnector{
    public:
    SQLiteConnector();                  /**< Default constructor */
    ~SQLiteConnector();                 /**< Destructor */
    void connectDB() override;          /**< Connect to db indicated by dbname and create table stock_tbl */
    void dropTable() override;          /**< Delete table stock_tbl if made in dbname */
    void dropTableandRebuild()override; /**< Delete */
    void disconnectDB()override;        /**< Disconnect from db indicated by dbname */
    sqlite3* getDbHandle();             /**< Access the db handle */
        

};



#endif