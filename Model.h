#include "Recipe.h"
#include "SQLiteConnector.h"
#include "StockTable.h"
#include <ctime>

class Model{
    private:
        //FoodAPIClass FoodConnector = FoodAPIClass();
        std::vector<Recipe> recipeList;
        SQLiteConnector dbConnection;
        StockTable dbContext;
    public:
        Model();
        ~Model();
        SQLiteConnector getDBConnection();
        StockTable getDbContext();
        std::vector<Recipe> getRecipeList();
        void setRecipeList(std::vector<Recipe> recipe_List);
        bool addFoodItem(FoodItem item);
        bool removeFoodItem(std::string itemName);
        bool modifyFoodItem(FoodItem item);
        FoodItem querySingleFoodItem(std::string item);
        std::vector<FoodItem> queryAllFoodItems();
        //std::vector<Recipe> processJSON(JSON queryReturn)
        std::vector<FoodItem> checkForExpiredFood();
        std::vector<FoodItem> checkForLowStock();



};
