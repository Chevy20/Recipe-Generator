#include "Model.h"
using namespace std;
Model::Model(){
    dbConnection = new SQLiteConnector();
    dbConnection->connectDB();
    dbContext = new StockTable(dbConnection->getDbHandle());
}
Model::~Model(){
    dbContext->~StockTable();
}
SQLiteConnector* Model::getDBConnection(){
    return dbConnection;
}
StockTable *Model::getDbContext(){
    return dbContext;
}
vector<Recipe> Model::getRecipeList(){
    return recipeList;
}
void Model::setRecipeList(std::vector<Recipe> recipe_List){
    recipeList = recipe_List;
}
bool Model::addFoodItem(FoodItem item){
    return dbContext->insert(&item);
}
bool Model::removeFoodItem(std::string itemName){
    return dbContext->remove(itemName);
}
bool Model::modifyFoodItem(FoodItem item){
    return dbContext->update(&item);
}
FoodItem Model::querySingleFoodItem(string item){
    return dbContext->select(item);
}
vector<FoodItem> Model::queryAllFoodItems(){
    return dbContext->selectAll();
}
/*std::vector<Recipe> Model::processJSON(JSON queryReturn){

}*/
vector<FoodItem> Model::checkForExpiredFood(){
    //TO be implemented later
}
vector<FoodItem> Model::checkForLowStock(){
    //To be implemented later
}