/**
    SQLiteConnector Object
    This headed contains the definitions for the SQLiteConnector object. It is a subclass of t_dbConnector
*/
#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include "t_dbConnector.h"

class SQLiteConnector : public t_dbConnector{
    public:
    /**
     * @brief Constructor - Sets the variables for this class.
     */
    SQLiteConnector();
    /**
     * @brief Destructor.
     */
    ~SQLiteConnector();
    /**
     * @brief Creates a connection with the SQL database.
     */
    void connectDB() override;
    /**
     * @brief Drops the stock_tbl.
     */
    void dropTable() override;
    /**
     * @brief Drops the stock_tbl and recreates it.
     */
    void dropTableandRebuild()override;
    /**
     * @brief Disconnects from stock_tbl.
     */
    void disconnectDB()override;
    /**
     * @brief Returns the database.
     * 
     * @return The handle to the database.
     */
    sqlite3* getDbHandle();
        

};



#endif
