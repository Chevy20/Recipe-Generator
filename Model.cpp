#include "Model.h"
using namespace std;

/*
Function:
Description:
Parameters:
Return:
*/
Model::Model(){
    dbConnection = new SQLiteConnector();
    dbConnection->connectDB();
    dbContext = new StockTable(dbConnection->getDbHandle());
}

/*
Function:
Description:
Parameters:
Return:
*/
Model::~Model(){
    dbContext->~StockTable();
}

/*
Function:
Description:
Parameters:
Return:
*/
SQLiteConnector* Model::getDBConnection(){
    return dbConnection;
}

/*
Function:
Description:
Parameters:
Return:
*/
StockTable *Model::getDbContext(){
    return dbContext;
}

/*
Function:
Description:
Parameters:
Return:
*/
vector<Recipe> Model::getRecipeList(){
    return recipeList;
}

/*
Function:
Description:
Parameters:
Return:
*/
void Model::setRecipeList(std::vector<Recipe> recipe_List){
    recipeList = recipe_List;
}

/*
Function:
Description:
Parameters:
Return:
*/
bool Model::addFoodItem(FoodItem item){
    return dbContext->insert(&item);
}

/*
Function:
Description:
Parameters:
Return:
*/
bool Model::removeFoodItem(std::string itemName){
    return dbContext->remove(itemName);
}

/*
Function:
Description:
Parameters:
Return:
*/
bool Model::modifyFoodItem(FoodItem item){
    return dbContext->update(&item);
}

/*
Function:
Description:
Parameters:
Return:
*/
FoodItem Model::querySingleFoodItem(string item){
    return dbContext->select(item);
}

/*
Function:
Description:
Parameters:
Return:
*/
vector<FoodItem> Model::queryAllFoodItems(){
    return dbContext->selectAll();
}

/*
Function:
Description:
Parameters:
Return:
*/
/*std::vector<Recipe> Model::processJSON(JSON queryReturn){

}*/

/*
Function:
Description:
Parameters:
Return:
*/
vector<FoodItem> Model::checkForExpiredFood(){
    //TO be implemented later
}

/*
Function:
Description:
Parameters:
Return:
*/
vector<FoodItem> Model::checkForLowStock(){
    //To be implemented later
}