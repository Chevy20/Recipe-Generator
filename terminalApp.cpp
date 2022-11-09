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



/*
Function:
Description:
Parameters:
Return:
*/
bool isDigit(const string& input){
    for(char const &ch : input){
        if(isdigit(ch) == 0)
        return false;
    }
    return true;
}

/*
Function:
Description:
Parameters:
Return:
*/
bool check(string input){
    if(!isDigit(input))
        return false;
    else{
        int num = atoi(input.c_str());
        if(num >=1 && num <=8){
            return true;
        }
    }
    return false;
}

/*
Function:
Description:
Parameters:
Return:
*/
bool checkDate(string input){
    struct tm tm;
    if(!strptime(input.c_str(), "%Y/%m/%d", &tm))
        return false;
    return true;
}

/*
Function:
Description:
Parameters:
Return:
*/
void printFoodItem(FoodItem item){
    cout<<"Item Name: " + item.getName()<<endl;
    cout<<"Quantity: " +to_string(item.getQuantity()) +" "+item.getMeasureUnit()<<endl;
    cout<<"Date Purchased: " + item.getDatePurchased()<<endl;
    cout<<"Expiry Date: " + item.getExpiry()<<endl;
    cout<<"You will get a low stock alert when there are " + to_string(item.getThreshold())+" "+item.getMeasureUnit()+" of this item left in stock"<<endl;
    
}


/*
Function:
Description:
Parameters:
Return:
*/
int main(int argc, char* argv[]){
    Model *theModel;
    theModel = new Model();
    

    string userInput;
    string itemName;
    string unitQuantity;
    string unitMeasureType;
    string datePurchased;
    string expirationDate;
    string storage;
    string quantityThreshold;
    string dateThreshold;
    FoodItem record;
    vector<FoodItem> multiSearch;
   
    int intInput;
    cout<<"Welcome to Freshcipes Terminal Prototype!" <<endl;
    cout<<"This application will help you search for recipes based on the food you have in your stock. If this is your first time using the app, insert food into your stock to get started!"<<endl;
    cout<<"Your stock will be stored when exiting the app.\n" <<endl;
    while (true){

        cout<<"1: Insert food item into your stock."<<endl;
        cout<<"2: Delete food item from your stock"<<endl;
        cout<<"3: Modify food item in your stock."<<endl;
        cout<<"4: Search stock for singular food item."<<endl;
        cout<<"5: Return all food items in Stock."<<endl;
        cout<<"6: Search for recipes based on items you specify."<<endl;
        cout<<"7: Search for recipes based on all items in your stock."<<endl;
        cout<<"8: Quit." << endl;
        cout<<"Please type a number, 1-8, to select an option: ";
        cin>> userInput;
        while(!check(userInput)){
            cout<<"Input invalid."<<endl;
            cout<<"Please type a number, 1-8, to select an option: ";
            cin>> userInput;
            
        }
        intInput = atoi(userInput.c_str());

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
               
                record = FoodItem(itemName,atoi(unitQuantity.c_str()),unitMeasureType,datePurchased,expirationDate,storage,atoi(quantityThreshold.c_str()));
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
            case 3:
                cout<<"\nUpdating an item in the Stock:"<<endl;
                cout<<"Please enter all information about the item you are updating:"<<endl;
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
                cout<<"How many days before this item expires would you like to receive an expiration alert: ";
                cin>> dateThreshold;
                 while(!isDigit(dateThreshold)){
                    cout<<"Non Numerical Input detected."<<endl;
                    cout<<"How many days before this item expires would you like to receive an expiration alert: ";
                    cin>> dateThreshold;
                }
                record = FoodItem(itemName,atoi(unitQuantity.c_str()),unitMeasureType,datePurchased,expirationDate,storage,atoi(quantityThreshold.c_str()));
                if(theModel->modifyFoodItem(record))
                    cout<<record.getName()+ " successfully updated!\n"<<endl;
                else
                    cout<<"Could not update that record.\n"<<endl;

                break;
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
                    cout<<"\nFood Close to expiration:"<<endl;
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
            case 6:
                break;
            case 7:
                break;
            case 8:
                cout<<"Shutting down!"<<endl;
                delete theModel;
                return 0;
            default:
                break;
        }
    }
    

     


}

