/**
 * @file SQLiteConnector.h
 * @author Matthew Cheverie
 * @brief SQLiteConnector header file. This file contains the defintions for the SQLiteConnector class. It inherits t_dbConnector.
 * It is used to directly create/connect to the SQLite3 database and initialize the tables.
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include "t_dbConnector.h"

class SQLiteConnector : public t_dbConnector{
    public:
    /**
     * @brief Constructor - Sets the variables for this class.
     * @author Matthew Cheverie
     */
    SQLiteConnector();
    /**
     * @brief Destructor.
     * @author Matthew Cheverie
     */
    ~SQLiteConnector();
    /**
     * @brief Creates a connection with the SQL database.
     * @author Matthew Cheverie
     */
    void connectDB() override;
    /**
     * @brief Drops the stock_tbl.
     * @author Matthew Cheverie
     */
    void dropTable() override;
    /**
     * @brief Drops the stock_tbl and recreates it.
     * @author Matthew Cheverie
     */
    void dropTableandRebuild()override;
    /**
     * @brief Disconnects from stock_tbl.
     * @author Matthew Cheverie
     */
    void disconnectDB()override;
    /**
     * @brief Returns the database.
     * 
     * @return The handle to the database.
     * @author Matthew Cheverie
     */
    sqlite3* getDbHandle();
        

};



#endif
