/**
 * @file Model.h
 * @author Matthew Cheverie
 * @brief Model header file. Contains the defininitions for the Model Class. The model is used as a middleman between the front end and the back end.
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
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
        /**
         * @brief Constructor - Sets the variables for this class.
         * @author Matthew Cheverie
         */
        Model();
        /**
         * @brief Destructor - Closes the connection to the database.
         * @author Matthew Cheverie
         */
        ~Model();
        /**
         * @brief Returns the food API.
         * 
         * @return The food API.
         * @author Matthew Cheverie
         */
        const FoodAPI* getFoodAPI();
        /**
         * @brief Returns the dbConnection object.
         * 
         * @return The dbConnection object.
         * @author Matthew Cheverie
         */
        SQLiteConnector* getDBConnection(); 
        /**
         * @brief Returns the dbContext object.
         * 
         * @return The dbContext object.
         * @author Matthew Cheverie
         */
        StockTable* getDbContext();
        /**
         * @brief Returns the list of the recipes that were queried for.
         * 
         * @return The list of queried recipes.
         * @author Matthew Cheverie
         */
        std::vector<Recipe> getQueriedRecipes();
        /**
         * @brief Sets the list of the recipes that were queried for
         * 
         * @param recipes The list of queried recipes to set.
         * @author Matthew Cheverie
         */
        void setQueriedRecipes(std::vector<Recipe> recipes);
        /**
         * @brief Adds a food item into the stock table.
         * 
         * @param item The food item to add.
         * 
         * @return Boolean for success.
         * @author Matthew Cheverie
         */
        bool addFoodItem(FoodItem item);
        /**
         * @brief Removes a food item from the stock table.
         * 
         * @param itemName The name of the food item to remove.
         * 
         * @return Boolean for success.
         * @author Matthew Cheverie
         */
        bool removeFoodItem(std::string itemName);
        /**
         * @brief Modifies an existing food item in the stock table.
         * 
         * @param item The modified food item.
         * 
         * @return Boolean for success.
         * @author Matthew Cheverie
         */
        bool modifyFoodItem(FoodItem item);
        /**
         * @brief Queries for and returns the desired food item.
         * 
         * @param item The name of the food item.
         * 
         * @return The found food item.
         * @author Matthew Cheverie
         */
        FoodItem querySingleFoodItem(std::string item);
        /**
         * @brief Queries and returns all food items in the database.
         * 
         * @return The list of all food items.
         * @author Matthew Cheverie
         */
        std::vector<FoodItem> queryAllFoodItems();
        /**
         * @brief Computes the stock after a recipe is used.
         * 
         * @param cookedRecipe The recipe that was made.
         * 
         * @return Boolean for success.
         * @author Matthew Cheverie
         */
        bool autoComputeStockAfterRecipe(Recipe cookedRecipe);
        /**
         * @brief Maually updates the stock after a recipe is used. Called when the measurements of the recipe and stock don't match.
         * 
         * @param items The list of food items that need to be updated.
         * 
         * @return Boolean for success.
         * @author Matthew Cheverie
         */
        bool manualCompleteStockAfterRecipe(std::vector<FoodItem> items);
        /**
         * @brief Checks for and returns a list of all expired food items.
         * 
         * @return A list of all exired food items.
         * @author Matthew Cheverie
         */
        std::vector<FoodItem> checkForExpiredFood();
        /**
         * @brief Checks for and returns a list of all food items with low stock.
         * 
         * @return A list of all food items with low stock.
         * @author Matthew Cheverie
         */
        std::vector<FoodItem> checkForLowStock();
        /**
         * @brief Checks if the units of the recipe match the stock measurements.
         * 
         * @param cookedRecipe The recipe to check.
         * 
         * @return True if the measurements are the same. False otherwise.
         * @author Matthew Cheverie
         */
        bool checkAutoStock(Recipe cookedRecipie);
        /**
         * @brief Prints all the recipes.
         * @author Matthew Cheverie
         */
        void printRecipeToConsole();
};
