#include "Model.h"
#include <iostream>
using namespace std;


/**
 * @brief Constructor - Sets the variables for this class.
 */
Model::Model(){
    //create new instance of SQLite connector. Connect to DB and create new dbconext passing in the handle from the dbConnection
    FoodConnection = &FoodAPI::getInstance();
    dbConnection = new SQLiteConnector();
    dbConnection->connectDB();
    dbContext = new StockTable(dbConnection->getDbHandle());
}


/**
 * @brief Destructor - Closes the connection to the database.
 */
Model::~Model(){
    dbContext->~StockTable(); 
}


/**
 * @brief Returns the dbConnection object.
 * 
 * @return The dbConnection object.
 */
SQLiteConnector* Model::getDBConnection(){
    return dbConnection;
}


/**
 * @brief Returns the dbContext object.
 * 
 * @return The dbContext object.
 */
StockTable *Model::getDbContext(){
    return dbContext;
}


/**
 * @brief Adds a food item into the stock table.
 * 
 * @param item The food item to add.
 * 
 * @return Boolean for success.
 */
bool Model::addFoodItem(FoodItem item){
    return dbContext->insert(&item);
}


/**
 * @brief Removes a food item from the stock table.
 * 
 * @param itemName The name of the food item to remove.
 * 
 * @return Boolean for success.
 */
bool Model::removeFoodItem(std::string itemName){
    return dbContext->remove(itemName);
}


/**
 * @brief Modifies an existing food item in the stock table.
 * 
 * @param item The modified food item.
 * 
 * @return Boolean for success.
 */
bool Model::modifyFoodItem(FoodItem item){
    return dbContext->update(&item);
}


/**
 * @brief Queries for and returns the desired food item.
 * 
 * @param item The name of the food item.
 * 
 * @return The found food item.
 */
FoodItem Model::querySingleFoodItem(string item){
    return dbContext->select(item);
}


/**
 * @brief Queries and returns all food items in the database.
 * 
 * @return The list of all food items.
 */
vector<FoodItem> Model::queryAllFoodItems(){
    return dbContext->selectAll();
}


/**
 * @brief Returns the food API.
 * 
 * @return The food API.
 */
const FoodAPI* Model::getFoodAPI(){
    return FoodConnection;
}


/**
 * @brief Checks for and returns a list of all expired food items.
 * 
 * @return A list of all exired food items.
 */
vector<FoodItem> Model::checkForExpiredFood(){
    vector<FoodItem> expiredFood;
    vector<FoodItem> items = dbContext->selectAll();
    
    time_t tempTime = time(0);
    tm* tempCurrentTime = localtime(&tempTime);
    int currentTime = (((1900 + tempCurrentTime->tm_year) * 10000) + ((1 + tempCurrentTime->tm_mon) * 100)) + (tempCurrentTime->tm_mday);
    
    while(items.size() > 0) {
        FoodItem tempFoodItem = items.back();
        
        string tempExp = tempFoodItem.getExpiry();
        tempExp.erase(remove(tempExp.begin(), tempExp.end(), '/'), tempExp.end());
        int foodExpiry = stoi(tempExp);
        
        if(currentTime >= foodExpiry)
            expiredFood.push_back(tempFoodItem);
        
        items.pop_back();
    }
    
    return expiredFood;
}


/**
 * @brief Checks for and returns a list of all food items with low stock.
 * 
 * @return A list of all food items with low stock.
 */
vector<FoodItem> Model::checkForLowStock(){
    vector<FoodItem> LowStock;
    vector<FoodItem> items = dbContext->selectAll();
    
    while(items.size() > 0) {
        FoodItem tempFoodItem = items.back();
        
        if(tempFoodItem.getQuantity() <= tempFoodItem.getThreshold())
            LowStock.push_back(tempFoodItem);
        
        items.pop_back();
    }
    
    return LowStock;
}


/**
 * @brief Computes the stock after a recipe is used.
 * 
 * @param cookedRecipe The recipe that was made.
 * 
 * @return Boolean for success.
 */
bool Model::autoComputeStockAfterRecipe(Recipe cookedRecipe){
    vector<RecipeItem> ingredients = cookedRecipe.getIngredients();
    for(int i = 0; i < ingredients.size(); i ++){
        RecipeItem item = ingredients[i];
        FoodItem stockItem = querySingleFoodItem(item.getItem());
        if(stockItem.decrementQty(item.getQuantity())){
            if(!modifyFoodItem(stockItem))
                return false;
        }
        else{
            return false;
        }

    }
    return true;
}


/**
 * @brief Checks if the units of the recipe match the stock measurements.
 * 
 * @param cookedRecipe The recipe to check.
 * 
 * @return True if the measurements are the same. False otherwise.
 */
bool Model::checkAutoStock(Recipe cookedRecipie){
    for(int i = 0; i < cookedRecipie.getIngredients().size(); i++){
        RecipeItem rItem = cookedRecipie.getIngredients()[i];
        FoodItem item = querySingleFoodItem(rItem.getItem());
        if(item.getMeasureUnit() != rItem.getItemMeasureUnit())
            return false;
    }
    return true;
}


/**
 * @brief Prints all the recipes.
 */
void Model::printRecipeToConsole(){
    cout<<"Here are the recipes returned from Spoonacular"<<endl;
    for(int i = 0; i <queriedRecipes.size(); i++){
        cout<<"Recipe "+to_string(i+1)+ ": "+queriedRecipes[i].getRecipeName()<<endl;
        cout<<"Ingredients Found: "<<endl;
        vector<RecipeItem> ingredients = queriedRecipes[i].getIngredients();
        for(int j = 0; j <ingredients.size(); j++){
            cout<<"Ingredient Name: " + ingredients[j].getItem()<<endl;
            cout<<"Quantity: "+to_string(ingredients[j].getQuantity()) +" "+ingredients[j].getItemMeasureUnit()<<endl;
        }
        cout<<"Missing Ingredients: "<<endl;
        vector<RecipeItem> mIngredients = queriedRecipes[i].getMissingIngredients();
        for(int j = 0; j < mIngredients.size(); j++){
            cout<<"Ingredient Name: " + mIngredients[j].getItem()<<endl;
            cout<<"Quantity: "+to_string(mIngredients[j].getQuantity()) +" "+ mIngredients[j].getItemMeasureUnit()<<endl;
        }
        cout<<"Image URL: "+queriedRecipes[i].getImageURL()<<endl;
        cout<<endl;
    }
}


//Note, once the autoStock check fails, this method will then be called using the update food items made by the front end as a parameter
/**
 * @brief Maually updates the stock after a recipe is used. Called when the measurements of the recipe and stock don't match.
 * 
 * @param items The list of food items that need to be updated.
 * 
 * @return Boolean for success.
 */
bool Model::manualCompleteStockAfterRecipe(std::vector<FoodItem> items){
    for(int i = 0; i < items.size(); i++)   {
        if(!modifyFoodItem(items[i]))
            return false;
    }
    return true; 
}


/**
 * @brief Returns the list of the recipes that were queried for.
 * 
 * @return The list of queried recipes.
 */
std::vector<Recipe> Model::getQueriedRecipes(){
    return queriedRecipes;
}


/**
 * @brief Sets the list of the recipes that were queried for
 * 
 * @param recipes The list of queried recipes to set.
 */
void Model::setQueriedRecipes(std::vector<Recipe> recipes){
    queriedRecipes = recipes;
}

