#ifndef STOCKTABLE_H
#define STOCKTABLE_H

#include "t_dbTableStrategy.h"
#include <vector>
#include "FoodItem.h"
#include <string>

class StockTable : public t_dbTableStrategy{

    public:
        FoodItem select (std::string key);
        std::vector<FoodItem> selectAll();


};



#endif