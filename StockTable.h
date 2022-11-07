#ifndef STOCKTABLE_H
#define STOCKTABLE_H

#include "t_dbTableStrategy.h"
#include <vector>
#include "FoodItem.h"
#include <string>
#include "sqlite3.h"

class StockTable : public t_dbTableStrategy{

    public:
        StockTable();
        StockTable(sqlite3* _db);
        ~StockTable();
        bool insert(void* item) override;
        bool update(void* item) override;
        bool remove(std::string itemName) override;
        FoodItem select (std::string key);
        std::vector<FoodItem> selectAll();
    private:
        sqlite3* db;


};

#endif