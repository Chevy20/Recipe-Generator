/*
    Header file for the Model object
    Contains declarations for Model Object
*/
#include "Recipe.h"
#include "SQLiteConnector.h"
#include "StockTable.h"
#include <string>
#include <ctime>
#include <algorithm>

class Model{
    private:
        //FoodAPIClass FoodConnector = FoodAPIClass();
        
        SQLiteConnector *dbConnection;  //database connection
        StockTable *dbContext;          //database context for table selection
    public:
        Model();
        ~Model();
        SQLiteConnector* getDBConnection(); 
        StockTable* getDbContext();
        bool addFoodItem(FoodItem item);
        bool removeFoodItem(std::string itemName);
        bool modifyFoodItem(FoodItem item);
        FoodItem querySingleFoodItem(std::string item);
        std::vector<FoodItem> queryAllFoodItems();
        //std::vector<Recipe> processJSON(JSON queryReturn)
        std::vector<FoodItem> checkForExpiredFood();
        std::vector<FoodItem> checkForLowStock();



};
