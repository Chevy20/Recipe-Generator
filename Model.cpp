#include "Model.h"
using namespace std;
Model::Model(){
    dbConnection = SQLiteConnector();
    dbConnection.connectDB();
    dbContext = StockTable(dbConnection.getDbHandle());
}
Model::~Model(){
    dbContext.~StockTable();
}
SQLiteConnector Model::getDBConnection(){
    return dbConnection;
}
StockTable Model::getDbContext(){
    return dbContext;
}
vector<Recipe> Model::getRecipeList(){
    return recipeList;
}
void Model::setRecipeList(std::vector<Recipe> recipe_List){
    recipeList = recipe_List;
}
bool Model::addFoodItem(FoodItem item){
    return dbContext.insert(&item);
}
bool Model::removeFoodItem(std::string itemName){
    return dbContext.remove(itemName);
}
bool Model::modifyFoodItem(FoodItem item){
    return dbContext.update(&item);
}
FoodItem Model::querySingleFoodItem(string item){
    return dbContext.select(item);
}
vector<FoodItem> Model::queryAllFoodItems(){
    return dbContext.selectAll();
}
/*std::vector<Recipe> Model::processJSON(JSON queryReturn){

}*/
vector<FoodItem> Model::checkForExpiredFood(){
    vector<FoodItem> expiredFood;
    vector<FoodItem> items = dbContext.selectAll();
    
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
vector<FoodItem> Model::checkForLowStock(){
    vector<FoodItem> LowStock;
    vector<FoodItem> items = dbContext.selectAll();
    
    while(items.size() > 0) {
        FoodItem tempFoodItem = items.back();
        
        if(tempFoodItem.getQuantity() <= tempFoodItem.getThreshold())
            LowStock.push_back(tempFoodItem);
        
        items.pop_back();
    }
    
    return LowStock;
}
