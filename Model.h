/*
    Header file for the Model object
    Contains declarations for Model Object
*/

#pragma once
#include "Recipe.h"
#include "SQLiteConnector.h"
#include "StockTable.h"
#include <string>
#include <ctime>
#include <algorithm>
#include "FoodAPI.hpp"

class Model{
    private:
        const FoodAPI* FoodConnection;
        SQLiteConnector *dbConnection;  //database connection
        StockTable *dbContext;          //database context for table selection
        
        std::vector<Recipe> queriedRecipes;
    public:
        Model();
        ~Model();
        const FoodAPI* getFoodAPI();
        SQLiteConnector* getDBConnection(); 
        StockTable* getDbContext();
        std::vector<Recipe> getQueriedRecipes();
        void setQueriedRecipes(std::vector<Recipe> recipes);
        bool addFoodItem(FoodItem item);
        bool removeFoodItem(std::string itemName);
        bool modifyFoodItem(FoodItem item);
        FoodItem querySingleFoodItem(std::string item);
        std::vector<FoodItem> queryAllFoodItems();
        bool autoComputeStockAfterRecipe(Recipe cookedRecipe);
        bool manualCompleteStockAfterRecipe(std::vector<FoodItem> items);
        std::vector<FoodItem> checkForExpiredFood();
        std::vector<FoodItem> checkForLowStock();
        bool checkAutoStock(Recipe cookedRecipie);
        void printRecipeToConsole();
      


};


