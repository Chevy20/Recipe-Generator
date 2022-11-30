#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include  <ctime>
#include "FoodItem.h"
#include "Recipe.h"
#include "RecipeItem.h"
#include "StockTable.h"
#include "SQLiteConnector.h"
#include "Model.h"
using namespace std;

// g++ terminalApp.cpp FoodItem.cpp SQLiteConnector.cpp StockTable.cpp Recipe.cpp RecipeItem.cpp model.cpp -lsqlite3

/*
Function: isDigit()
Description: Function to check if an input string represents a number
Parameters: const string& input: input string
Return: true if string is a number, false it not
*/
bool isDigit(const string& input){
    for(char const &ch : input){
        if(isdigit(ch) == 0 && &ch!=".")
        return false;
    }
    return true;
}

/*
Function: check()
Description: Function to check if input is a valid command
Parameters: string input: input string from user to select a command
Return: true if string is valid, false if not
*/
bool check(string input){
    if(!isDigit(input))
        return false;
    else{
        float num = stof(input);
        if(num >=1 && num <=9){
            return true;
        }
    }
    return false;
}
bool checkRecipe(string input,vector<Recipe> recipieList){
    if(!isDigit(input))
        return false;
    else{
        float num = stof(input);
        if(num >=1 && num <=recipieList.size()){
            return true;
        }
    }
    return false;
}

/*
Function: checkDate()
Description: Function to check validity of date
Parameters: string input: input to represent a date
Return: true if date is valid, false if not
*/
bool checkDate(string input){
    struct tm tm;
    if(!strptime(input.c_str(), "%Y/%m/%d", &tm))
        return false;
    return true;
}

/*
Function: printFoodItem()
Description: Print the parameters of a given foodItem to console
Parameters: FoodItem item: item to be printed to console
Return: none
*/
void printFoodItem(FoodItem item){
    cout<<"Item Name: " + item.getName()<<endl;
    cout<<"Quantity: " +to_string(item.getQuantity()) +" "+item.getMeasureUnit()<<endl;
    cout<<"Date Purchased: " + item.getDatePurchased()<<endl;
    cout<<"Expiry Date: " + item.getExpiry()<<endl;
    cout<<"You will get a low stock alert when there are " + to_string(item.getThreshold())+" "+item.getMeasureUnit()+" of this item left in stock\n"<<endl;
    
}


/*
Function: main()
Description: main function of the terminalAPP
Parameters:int argc: commandLine arg counter, char* argv[]: command line arguments
Return: 0
*/
int main(int argc, char* argv[]){

    // Declare Variables 
    Model *theModel;        //the model object to interface with the back end
    theModel = new Model();
    string userInput;           //user input from terminal
    string itemName;            //item name for creation of food item
    string unitQuantity;        //unit quantity for creation of food item
    string unitMeasureType;     //unit measurement type for creation of food item
    string datePurchased;       //date purchased for creation of food item
    string expirationDate;      //expiration date for creation of food item
    string storage;             //storage spot for creation of food item
    string quantityThreshold;   //item name for creation of food item
    FoodItem record;            //Fooditem used to contain singular FoodItems
    vector<FoodItem> multiSearch;   //Vector used to contain multiple FoodItems
    int intInput;                   //used to store integer input 

    //Welcome message
    cout<<"Welcome to Freshcipes Terminal Application" <<endl;
    cout<<"This application will help you search for recipes based on the food you have in your stock. If this is your first time using the app, insert food into your stock to get started!"<<endl;
    cout<<"Your stock will be stored when exiting the app.\n" <<endl;

    //Application Loop
    while (true){

        cout<<"1: Insert food item into your stock."<<endl;
        cout<<"2: Delete food item from your stock"<<endl;
        cout<<"3: Modify food item in your stock."<<endl;
        cout<<"4: Search stock for singular food item."<<endl;
        cout<<"5: Return all food items in Stock."<<endl;
        cout<<"6: Search for recipes based on items you specify."<<endl;
        cout<<"7: Search for recipes based on all items in your stock."<<endl;
        cout<<"8: Select a Recipe to cook."<<endl;
        cout<<"9: Quit." << endl;
        cout<<"Please type a number, 1-9, to select an option: ";
        cin>> userInput;
        while(!check(userInput)){
            cout<<"Input invalid."<<endl;
            cout<<"Please type a number, 1-9, to select an option: ";
            cin>> userInput;
            
        }
        intInput = atoi(userInput.c_str());


        //Command selection
        switch (intInput)
        {
            case 1:
                cout<<"\nInserting an Item into stock:"<<endl;

                cout<<"Please enter the name of the food item: ";
                cin>> itemName;
                while(itemName == ""){
                    cout<<"Invalid Input."<<endl;
                    cout<<"Please enter the name of the food item: ";
                    cin>> itemName;
                }
                cout<<"Please enter the measurement unit for the quantity of food. Example: apples(for whole fruit, use the word for plural of the fruit), g, kg, oz, ml, L, lbs: ";
                cin>> unitMeasureType;
                while(unitMeasureType == ""){
                    cout<<"Invalid Input."<<endl;
                    cout<<"Please enter the measurement unit for the quantity of food. Example: apples(for whole fruit, use the word for plural of the fruit), g, kg, oz, ml, L, lbs: ";
                    cin>> unitMeasureType;
                }
                cout<<"Please enter the numerical quantity of food without the unit of measurement: ";
                cin>> unitQuantity;
                while(!isDigit(unitQuantity)){
                    cout<<"Non Numerical Input detected."<<endl;
                    cout<<"Please enter the quantity of food without the unit of measurement: ";
                    cin>> unitQuantity;
                }
                cout<<"Please enter the date purchased in the form YYYY/MM/DD:  ";
                cin>> datePurchased;
                while(!checkDate(datePurchased)){
                    cout<<"Invalid Date Input detected."<<endl;
                    cout<<"Please enter the date purchased in the form YYYY/MM/DD:  ";
                    cin>> datePurchased;
                }

                cout<<"Please enter the expiry date of the food item in the form YYYY/MM/DD: ";
                cin>> expirationDate;
                while(!checkDate(expirationDate)){
                    cout<<"Invalid Date Input detected."<<endl;
                    cout<<"Please enter the expiry date of the food item in the form YYYY/MM/DD : ";
                    cin>> expirationDate;
                }

                cout<<"Storage Location of the Food item: ";
                cin>> storage;
                while(storage == ""){
                    cout<<"Invalid Date Input detected."<<endl;
                    cout<<"Storage Location of the Food item: ";
                    cin>> storage;
                }

                cout<<"Please enter the quantity of food for this item that should trigger a low quantity alert: ";
                cin>> quantityThreshold;
                while(!isDigit(quantityThreshold)){
                    cout<<"Non Numerical Input detected."<<endl;
                    cout<<"Please enter the quantity of food for this item that should trigger a low quantity alert: ";
                    cin>> quantityThreshold;
                }
               
                record = FoodItem(itemName,stof(unitQuantity),unitMeasureType,datePurchased,expirationDate,storage,stof(quantityThreshold));
                if(theModel->addFoodItem(record))
                    cout<<record.getName() + " sucessfully added to stock!\n"<<endl;
                else
                    cout<<"Could not add that record into stock. Review Parameters and try again.\n"<<endl;
                break;

            case 2:
                cout<<"\nDeleting an item from Stock:"<<endl;
                cout<<"Please enter the name of the food item you wish to remove from the stock: ";
                cin>>itemName;
                if(theModel->removeFoodItem(itemName))
                    cout<<itemName+ " successfully deleted from the stock.\n"<<endl;
                else
                    cout<<"Could not delete that record from stock.\n"<<endl;
                break;
            case 3:{
                cout<<"\nUpdating an item in the Stock:"<<endl;
                cout<<"Please enter all information about the item you are updating:"<<endl;
                cout<<"Please enter the name of the food item: ";
                cin>> itemName;
                while(itemName == ""){
                    cout<<"Invalid Input."<<endl;
                    cout<<"Please enter the name of the food item: ";
                    cin>> itemName;
                }
                FoodItem item = theModel->querySingleFoodItem(itemName);
                if(item.getName() != ""){
                    cout<<"Please enter the measurement unit for the quantity of food. Example: apples(for whole fruit, use the word for plural of the fruit), g, kg, oz, ml, L, lbs: ";
                cin>> unitMeasureType;
                while(unitMeasureType == ""){
                    cout<<"Invalid Input."<<endl;
                    cout<<"Please enter the measurement unit for the quantity of food. Example: apples(for whole fruit, use the word for plural of the fruit), g, kg, oz, ml, L, lbs: ";
                    cin>> unitMeasureType;
                }
                cout<<"Please enter the numerical quantity of food without the unit of measurement: ";
                cin>> unitQuantity;
                while(!isDigit(unitQuantity)){
                    cout<<"Non Numerical Input detected."<<endl;
                    cout<<"Please enter the quantity of food without the unit of measurement: ";
                    cin>> unitQuantity;
                }
                cout<<"Please enter the date purchased in the form YYYY/MM/DD:  ";
                cin>> datePurchased;
                while(!checkDate(datePurchased)){
                    cout<<"Invalid Date Input detected."<<endl;
                    cout<<"Please enter the date purchased in the form YYYY/MM/DD:  ";
                    cin>> datePurchased;
                }

                cout<<"Please enter the expiry date of the food item: ";
                cin>> expirationDate;
                while(!checkDate(expirationDate)){
                    cout<<"Invalid Date Input detected."<<endl;
                    cout<<"Please enter the expiry date of the food item: ";
                    cin>> expirationDate;
                }

                cout<<"Storage Location of the Food item: ";
                cin>> storage;
                while(storage == ""){
                    cout<<"Invalid Date Input detected."<<endl;
                    cout<<"Storage Location of the Food item: ";
                    cin>> storage;
                }

                cout<<"Please enter the quantity of food for this item that should trigger a low quantity alert: ";
                cin>> quantityThreshold;
                while(!isDigit(quantityThreshold)){
                    cout<<"Non Numerical Input detected."<<endl;
                    cout<<"Please enter the quantity of food for this item that should trigger a low quantity alert: ";
                    cin>> quantityThreshold;
                }
            
                record = FoodItem(itemName,stof(unitQuantity),unitMeasureType,datePurchased,expirationDate,storage,stof(quantityThreshold));
                if(theModel->modifyFoodItem(record))
                    cout<<record.getName()+ " successfully updated!\n"<<endl;
                else
                    cout<<"Could not update that record.\n"<<endl;

                }
                
                break;
            }
                
            case 4:
                cout<<"\nSearch stock for singular type of food:"<<endl;
                cout<<"Please enter the name of the food you are searching for: ";
                cin>> itemName;
                record = theModel->querySingleFoodItem(itemName);
                if(record.getName() != ""){
                    cout<<"\nQuery results:"<<endl;
                    printFoodItem(record);
                }
                else{
                    cout<<"Could not find that item in the stock."<<endl;
                }
                break;
            case 5:
                cout<<"List entire stock:"<<endl;
                cout<<"\nQuery results:"<<endl;
                multiSearch = theModel->queryAllFoodItems();
                for(int i = 0; i < multiSearch.size(); i++){
                    printFoodItem(multiSearch[i]);
                }
                multiSearch = theModel->checkForExpiredFood();
                if(multiSearch.size() != 0){
                    cout<<"\nExpired Food:"<<endl;
                    for(int i = 0; i < multiSearch.size(); i++){
                        printFoodItem(multiSearch[i]);
                    }
                }
                
                multiSearch = theModel->checkForLowStock();
                if(multiSearch.size() != 0){
                    cout<<"\nFood low in stock:"<<endl;
                    for(int i = 0; i < multiSearch.size(); i++){
                        printFoodItem(multiSearch[i]);
                    }
                }
                
                cout<<"\n"<<endl;
                break;
            case 6:{
                cout<<"Your Stock: "<<endl;
                vector<FoodItem> stock = theModel->queryAllFoodItems();
                for(int i = 0; i < stock.size(); i++){
                    cout<<"Item Name: "+stock[i].getName()<<endl;
                }
                cout<<"Please enter food items existing in your stock until you have the items you wish to make a recipe with. Enter an exclamation point (!) to signify you are done entering food."<<endl;
                vector<string> items;
                string in=""; 
                while(in != "!"){
                    cin>> in;
                    FoodItem item = theModel->querySingleFoodItem(in);
                    if(item.getName()!= ""){
                        items.push_back(in);
                    }
                    else{
                        if(in != "!")
                            cout<<"Item not in stock, please try another item."<<endl;
                    }
                }
                string q = "";
                for(int i = 0; i <items.size(); i++){
                    if(i!= items.size() -1){
                        q += items[i] + ",";
                    }
                    else{
                        q += items[i];
                    }
                }
                cout<<"Searching spoonacular for Recipes based on the food items you specified."<<endl;
                vector<Recipe> apiSearch = theModel->getFoodAPI()->getRecipeBySpecificIngredients(q);
                theModel->setQueriedRecipes(apiSearch);
                theModel->printRecipeToConsole();
                break;
            }
                
            //API call for all stock
            case 7:{
                cout<<"Searching spoonacular for Recipes based on all food items in your stock."<<endl;
                vector<Recipe> apiSearch = theModel->getFoodAPI()->getRecipeByIngredients(theModel);
                theModel->setQueriedRecipes(apiSearch);
                theModel->printRecipeToConsole();
                break;
            }
            case 8:{
                vector<Recipe> rList = theModel->getQueriedRecipes();
                if(rList.size() != 0){
                    theModel->printRecipeToConsole();
                    cout<<"Please the number of the recipe you would like to cook."<<endl;
                    cout<<"If your stock can be managed automatically, the necessary deductions will be made and you will see your updated stock."<<endl;
                    cout<<"If your stock cannot be managed automatically, you will be prompted to enter the new quantity for each item used in the recipie."<<endl;
                    cout<<"Please type the number of the recipe you would like to cook: ";
                    cin>> userInput;
                    while(!checkRecipe(userInput,rList)){
                        cout<<"Input invalid."<<endl;
                        cout<<"Please type the number of the recipe you would like to cook: ";
                        cin>> userInput;
                    }
                    Recipe selectedRecipe = rList[atoi(userInput.c_str())-1];

                    //AutoComputeStock
                    if(theModel->checkAutoStock(selectedRecipe)){
                        cout<<"Auto stock management possible."<<endl;
                        if(!theModel->autoComputeStockAfterRecipe(selectedRecipe))
                            cout<<"Error in completing stock update. Please manually check and update your stock."<<endl;
                        else
                            cout<<"Stock updated successfully!"<<endl;
                    }
                    //Manually compute stock
                    else{
                        cout<<"Auto stock management not possible for " +selectedRecipe.getRecipeName()<<endl;
                        vector<FoodItem> updatedStock; 
                        vector<RecipeItem> ingredients = selectedRecipe.getIngredients();
                        for(int i = 0; i <ingredients.size(); i++){
                            FoodItem item = theModel->querySingleFoodItem(ingredients[i].getItem());
                            if(item.getName()!= ""){
                                cout<<"Item in stock before cooking:"<<endl;
                                cout<<"Item Name: "+item.getName()<<endl;
                                cout<<"Item quantity: "+to_string(item.getQuantity())+" "+item.getMeasureUnit()<<endl;
                                cout<<"Please enter the amount of this ingredient used while cooking. Unit of measurement is "+item.getMeasureUnit()+": ";
                                cin>>userInput;
                                while(!isDigit(userInput) || stof(userInput) > item.getQuantity()||stof(userInput) <= 0)  {
                                    cout<<"Invalid entry. Check to make sure that the value entered is greater than 0, less than or equal to the amount you have, and is numerical"<<endl;
                                    cin>>userInput;
                                }
                                item.decrementQty(stof(userInput));
                                theModel->modifyFoodItem(item);
                            }
                            else{
                                cout<<"Possible ingredient discrepancy. Check recipe to ensure that you have all ingredients needed"<<endl;
                                break;
                            }
                            
                        }

                    }
                }
                else{
                    cout<<"No recipes have been queried for. Search for some recipes first."<<endl;
                }
                
                break;
                
            }
            case 9:
                cout<<"Shutting down!"<<endl;
                delete theModel;
                return 0;
            default:
                break;
        }
    }
    

     


}

