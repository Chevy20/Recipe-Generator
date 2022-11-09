/*
    SQLiteConnector Object
    This headed contains the definitions for the SQLiteConnector object. It is a subclass of t_dbConnector
*/
#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include "t_dbConnector.h"

class SQLiteConnector : public t_dbConnector{
    public:
    SQLiteConnector();
    ~SQLiteConnector();
    void connectDB() override;
    void dropTable()override;
    void dropTableandRebuild()override;
    void disconnectDB()override;
    sqlite3* getDbHandle();
        

};



#endif