#include <iostream>
#include <stdlib.h>
#include "FoodItem.h"
#include "Recipe.h"
#include "RecipeItem.h"
#include "StockTable.h"
#include "SQLiteConnector.h"
using namespace std;

bool isDigit(const string& input){
    for(char const &ch : input){
        if(isdigit(ch) == 0)
        return false;
    }
    return true;
}

int main(){

    SQLiteConnector connection = SQLiteConnector();
    connection.connectDB();
    StockTable StockTableContext = StockTable(connection.getDbHandle());

    string command;
    int userInput;
    cout<<"Welcome to Freshcipes Terminal Prototype!" <<endl;
    cout<<"This application will help you search for recipes based on the food you have in your stock. If this is your first time using the app, insert food into your stock to get started!"<<endl;
    cout<<"Your stock will be stored when exiting the app." <<endl;
    cout<<"1: Insert food item into your stock."<<endl;
    cout<<"2: Delete food item from your stock"<<endl;
    cout<<"3: Modify food item in your stock."<<endl;
    cout<<"4: Search stock for singular food item."<<endl;
    cout<<"5: Return all food items in Stock."<<endl;
    cout<<"6: Search for recipes based on items you specify."<<endl;
    cout<<"7: Search for recipes based on all items in your stock"<<endl;

    cout<<"Please type a number, 1-7, to select an option: ";
    cin>> command;
    /*
   
    while(){
        cout<<"Input invalid."<<endl;
        cout<<"Please type a number, 1-7, to select an option: ";
        cin>> command;
    }
    userInput = atoi(command.c_str());

    switch (userInput)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        break;
    }

     */


}

