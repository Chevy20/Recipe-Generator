#include "Model.h"
#include <iostream>
using namespace std;

/*
Function: Constructor for Model
Description: This will create the model object
Parameters:none
Return: Model object
*/
Model::Model(){
    //create new instance of SQLite connector. Connect to DB and create new dbconext passing in the handle from the dbConnection
    FoodConnection = &FoodAPI::getInstance();
    dbConnection = new SQLiteConnector();
    dbConnection->connectDB();
    dbContext = new StockTable(dbConnection->getDbHandle());
}

/*
Function: Destructor for Model
Description: This will close connection to the db
Parameters:none
Return:none
*/
Model::~Model(){
    dbContext->~StockTable();
    delete FoodConnection;
    
}

/*
Function: getDBConnection
Description: Getter function for the dbConnection object
Parameters: non
Return: SQLiteConnector* representing the connection to the db
*/
SQLiteConnector* Model::getDBConnection(){
    return dbConnection;
}


/*
Function:getDBContext()
Description: Getter function for the dbContext
Parameters: none
Return: StockTable* represnting the database context for the table we wish to interact with
*/
StockTable *Model::getDbContext(){
    return dbContext;
}





/*
Function: addFoodItem()
Description: Function to add a food item into the stock table
Parameters: FoodItem item: item to be added
Return: true if added, false if not
*/
bool Model::addFoodItem(FoodItem item){
    return dbContext->insert(&item);
}

/*
Function: removeFoodItem()
Description: Function to remove a food item from the database
Parameters: string itemName: itemName to remove from the database
Return: true if remove, false if not
*/
bool Model::removeFoodItem(std::string itemName){
    return dbContext->remove(itemName);
}

/*
Function: modifyFoodItems()
Description: Function to modify an existing food item in the table
Parameters: FoodItem item: modified food item to modify in the table
Return: true if updated, false if not
*/
bool Model::modifyFoodItem(FoodItem item){
    return dbContext->update(&item);
}

/*
Function: querySingleFoodItem()
Description: Function to query for a single food item
Parameters: string item: the name of an item to query for
Return: FoodItem objefct representing the FoodItem object found. If query didnt find an item, return a blank food item
*/
FoodItem Model::querySingleFoodItem(string item){
    return dbContext->select(item);
}

/*
Function: queryAllFoodItems()
Description:Function to query for all food items in the database
Parameters: none
Return: vector<FoodItem> representing all food items in the database
*/
vector<FoodItem> Model::queryAllFoodItems(){
    return dbContext->selectAll();
}
const FoodAPI* Model::getFoodAPI(){
    return FoodConnection;
}


/*
Function: checkForExpiredFood()
Description:Function to check for expired food in stock if expiry date is before current date
Parameters: none
Return: vector<FoodItems> representing all items that are expired
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

/*
Function: checkForLowStock()
Description:Function to check for low stock if an items stock is below or eqaul to the threshold
Parameters: none
Return: vector<FoodItems> representing all items that are low on stock
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
bool Model::checkAutoStock(Recipe cookedRecipie){
    for(int i = 0; i < cookedRecipie.getIngredients().size(); i++){
        RecipeItem rItem = cookedRecipie.getIngredients()[i];
        FoodItem item = querySingleFoodItem(rItem.getItem());
        if(item.getMeasureUnit() != rItem.getItemMeasureUnit())
            return false;
    }
    return true;
}

void Model::printRecipeToConsole(){
    cout<<"Here are the recipies returned from Spoonacular"<<endl;
    for(int i = 0; i <queriedRecipes.size(); i++){
        cout<<"Recipe "+to_string(i+1)+ ": "+queriedRecipes[i].getRecipeName()<<endl;
        cout<<"Ingredients: "<<endl;
        vector<RecipeItem> ingredients = queriedRecipes[i].getIngredients();
        for(int j = 0; j <ingredients.size(); j++){
            cout<<"Ingredient Name: " + ingredients[j].getItem()<<endl;
            cout<<"Quantity: "+to_string(ingredients[j].getQuantity()) +" "+ingredients[j].getItemMeasureUnit()<<endl;
        }
        cout<<endl;
    }
}

//Note, once the autoStock check fails, this method will then be called using the update food items made by the front end as a parameter
bool Model::manualCompleteStockAfterRecipe(std::vector<FoodItem> items){
    for(int i = 0; i < items.size(); i++)   {
        if(!modifyFoodItem(items[i]))
            return false;
    }
    return true; 
}
std::vector<Recipe> Model::getQueriedRecipes(){
    return queriedRecipes;
}
void Model::setQueriedRecipes(std::vector<Recipe> recipes){
    queriedRecipes = recipes;
}

