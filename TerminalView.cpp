/**
 * @file TerminalView.cpp
 * @author Matthew Cheverie
 * @brief TerminalView program. This cpp file contains the implemntation of the terminalView class
 * It will make a view that is meant for the terminal
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TerminalView.h"
using namespace std;

/**
 * @brief constructor for the Terminalview
 * @param model The pointer object that points to a model object used to interface with the backend
 * @author Matthew Cheverie
 */
TerminalView::TerminalView(Model *model){
    this->model = model;
}
/**
 * @brief This function will check if the given input string is a digit. Ignores '.' to allow for floats
 * @param input The input string
 * @author Matthew Cheverie
 * @return true if digit, false if not. 
 */
 bool TerminalView::isDigit(const std::string& input){
    for(char const &ch : input){
        if(isdigit(ch) == 0 && &ch!=".")
        return false;
    }
    return true;
 }

/**
 * @brief Checks if a given input will be accepted when the user is prompted to enter a command
 * @param input the input string
 * @author Matthew Cheverie
 * @return true if valid input, false it not
 */
bool TerminalView::check(std::string input){
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

/**
 * @brief Checks if the input to select a recipe to cook is valid
 * @param input the input string
 * @param recipieList the list of recipe objects
 * @author Matthew Cheverie
 * @return true if valid recipe input, false if not
 */
bool TerminalView::checkRecipe(std::string input, std::vector<Recipe> recipieList){
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
 /**
 * @brief check to see if the date inputed is valid
 * @param input the input string
 * @author Matthew Cheverie
 * @return true if valid date, false if not
 */
bool TerminalView::checkDate(std::string input){
    struct tm tm;
    if(!strptime(input.c_str(), "%Y/%m/%d", &tm))
        return false;
    return true;
}
/**
 * @brief  prints out a FoodItems attributes to the console in a styleized way.
 * @param item The food item object to be printed
 * @author Matthew Cheverie
 */
void TerminalView::printFoodItem(FoodItem item){
    cout<<"Item Name: " + item.getName()<<endl;
    cout<<"Quantity: " +to_string(item.getQuantity()) +" "+item.getMeasureUnit()<<endl;
    cout<<"Date Purchased: " + item.getDatePurchased()<<endl;
    cout<<"Expiry Date: " + item.getExpiry()<<endl;
    cout<<"You will get a low stock alert when there are " + to_string(item.getThreshold())+" "+item.getMeasureUnit()+" of this item left in stock"<<endl;
}
/**
 * @brief Destructor for TerminalView
 * @author Matthew Cheverie
 */
TerminalView::~TerminalView(){
    delete this;
}
/**
 * @brief setter function for the model pointer. Inherited from View
 * @param model the new model object to be set
 * @author Matthew Cheverie
 */
void TerminalView::setModel(Model *model){
    this->model=model;
}

 /**
 * @brief Getter function for the model pointer. Inherited from View
 * @author Matthew Cheverie
 */
Model* TerminalView::getModel(){
    return model;
}
/**
 * @brief Function to display the view. Inherited from View
 * @author Matthew Cheverie
 */
void TerminalView::display() {
    Model* modl =model;         //makes a model pointer equal to the model instance variable
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
    bool flag = true;
    //Welcome message
    cout<<"Welcome to Freshcipes Terminal Application" <<endl;
    cout<<"This application will help you search for recipes based on the food you have in your stock. If this is your first time using the app, insert food into your stock to get started!"<<endl;
    cout<<"Your stock will be stored when exiting the app.\n" <<endl;

    //Application Loop
    while (flag){

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
                if(modl->addFoodItem(record))
                    cout<<record.getName() + " sucessfully added to stock!\n"<<endl;
                else
                    cout<<"Could not add that record into stock. Review Parameters and try again.\n"<<endl;
                break;

            case 2:
                cout<<"\nDeleting an item from Stock:"<<endl;
                cout<<"Please enter the name of the food item you wish to remove from the stock: ";
                cin>>itemName;
                if(modl->removeFoodItem(itemName))
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
                FoodItem item = modl->querySingleFoodItem(itemName);
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
                if(modl->modifyFoodItem(record))
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
                record = modl->querySingleFoodItem(itemName);
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
                multiSearch = modl->queryAllFoodItems();
                for(int i = 0; i < multiSearch.size(); i++){
                    printFoodItem(multiSearch[i]);
                }
                multiSearch = modl->checkForExpiredFood();
                if(multiSearch.size() != 0){
                    cout<<"\nExpired Food:"<<endl;
                    for(int i = 0; i < multiSearch.size(); i++){
                        printFoodItem(multiSearch[i]);
                    }
                }
                
                multiSearch = modl->checkForLowStock();
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
                vector<FoodItem> stock = modl->queryAllFoodItems();
                for(int i = 0; i < stock.size(); i++){
                    cout<<"Item Name: "+stock[i].getName()<<endl;
                }
                cout<<"Please enter food items existing in your stock until you have the items you wish to make a recipe with. Enter an exclamation point (!) to signify you are done entering food."<<endl;
                vector<string> items;
                string in=""; 
                while(in != "!"){
                    cin>> in;
                    FoodItem item = modl->querySingleFoodItem(in);
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
                vector<Recipe> apiSearch = modl->getFoodAPI()->getRecipeBySpecificIngredients(q);
                modl->setQueriedRecipes(apiSearch);
                modl->printRecipeToConsole();
                break;
            }
                
            //API call for all stock
            case 7:{
                // Mass query for entire stock.
                cout<<"Searching spoonacular for Recipes based on all food items in your stock."<<endl;
                vector<Recipe> apiSearch = modl->getFoodAPI()->getRecipeByIngredients(modl);
                modl->setQueriedRecipes(apiSearch);
                modl->printRecipeToConsole();
                break;
            }
            
            //Select a recipise too cook
            case 8:{
                //get recipe list 
                vector<Recipe> rList = modl->getQueriedRecipes();
                // if there is at least one recipe returned
                if(rList.size() != 0){
                    // print recipes to console
                    modl->printRecipeToConsole();
                    cout<<"Please the number of the recipe you would like to cook."<<endl;
                    cout<<"If your stock can be managed automatically, the necessary deductions will be made and you will see your updated stock."<<endl;
                    cout<<"If your stock cannot be managed automatically, you will be prompted to enter the new quantity for each item used in the recipie."<<endl;
                    cout<<"Please type the number of the recipe you would like to cook: ";
                    //ask user to select a recipe to cook
                    cin>> userInput;
                    while(!checkRecipe(userInput,rList)){
                        cout<<"Input invalid."<<endl;
                        cout<<"Please type the number of the recipe you would like to cook: ";
                        cin>> userInput;
                    }
                    Recipe selectedRecipe = rList[atoi(userInput.c_str())-1];

                    //Check if auto stock managment is possible. Only possible is units of measurement match for each recipe ingredient and its corresponding entry in the db
                    if(modl->checkAutoStock(selectedRecipe)){
                        cout<<"Auto stock management possible."<<endl;
                        //if auto stock fails for some reason
                        if(!modl->autoComputeStockAfterRecipe(selectedRecipe))
                            cout<<"Error in completing stock update. Please manually check and update your stock."<<endl;
                        else
                            cout<<"Stock updated successfully!"<<endl;
                    }
                    //Manually compute stock
                    else{
                        // If auto stock managment is not possible 
                        cout<<"Auto stock management not possible for " +selectedRecipe.getRecipeName()<<endl;
                        vector<FoodItem> updatedStock; 
                        vector<RecipeItem> ingredients = selectedRecipe.getIngredients();

                        //get corresponding food item from stock 
                        for(int i = 0; i <ingredients.size(); i++){
                            FoodItem item = modl->querySingleFoodItem(ingredients[i].getItem());
                            /// if item is found, sometimes queries from API return a hit on similar ingredient names. For example
                            /// if we have apples in our stock, a recipe might get returned with a used ingredient as green apples
                            /// we cannot manage stock for item we dont have so we go to the else
                            if(item.getName()!= ""){
                                //Show user the amount of item before cooking. Ask how much they used while cooking. Compute new stock and update item in db
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
                                modl->modifyFoodItem(item);
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

            //Quit out of app
            case 9:{
                cout<<"Shutting down!"<<endl;
                delete modl;
                flag = false;
            }
                
            default:
                break;
        }
    }
    
}





