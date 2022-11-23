#include <iostream>
#include <stdlib.h>
#include <signal.h>

#include "FoodItem.h"
#include "Recipe.h"
#include "RecipeItem.h"

using namespace std;

// g++ recipeApp.cpp Recipe.cpp RecipeItem.cpp FoodItem.cpp

/*
Function: main()
Description: main function of the terminalAPP
Parameters:int argc: commandLine arg counter, char* argv[]: command line arguments
Return: 0
*/
int main(int argc, char* argv[]){
    FoodItem bread("bread", 30, "slices", "2022/12/01", "2023/04/01", "fridge", 4);
    FoodItem butter("butter", 100, "ounces", "2022/12/01", "2023/04/01", "fridge", 10);
    FoodItem jam("jam", 400, "mL", "2022/12/01", "2023/04/01", "fridge", 50);

    vector<FoodItem> inventory;
    inventory.push_back(bread);
    inventory.push_back(butter);
    inventory.push_back(jam);

    RecipeItem rBread(bread, 2, "slices");
    RecipeItem rButter(butter, 5, "ounces");

    vector<RecipeItem> recipe;
    recipe.push_back(rBread);
    recipe.push_back(rButter);

    map<string, int> nutri;

    Recipe Toast("Toast", recipe, nutri, 1);

    cout << "Influence " << Toast.getRecipeName() << " Recipe" << endl;
    cout << "Serving size starts at: " << Toast.getYield() << endl;
    cout << "Ingredients:" << endl;
    for (auto & ingredient : Toast.getIngredients()){
        cout << ingredient.getItem().getName() << ": " << ingredient.getQuantity() << " " << ingredient.getItemMeasureUnit() << endl;
    }
    cout << endl;

    string userInput;

    while (true){
        cout << "1 - select new portions size" << endl;
        cout << "2 - change quantity of specific ingredient" << endl;
        cout << "3 - swap ingredient for another" << endl;
        cout << "4 - add new ingredient to recipe\n" << endl;

        int choice;
        cin >> userInput;
        cout << endl;

        if (userInput.compare("exit") == 0){
            break;
        }

        try{
            choice = atoi(userInput.c_str());
        } catch (exception) {
            cout << "not a number" << endl;
            continue;
        }

        switch (choice){
            case 1:
                {
                    cout << "what are the new number of servings: ";
                    cin >> userInput;
                    cout << endl;

                    float nServings = atof(userInput.c_str());

                    Toast.changeProportions(nServings);

                    cout << Toast.getRecipeName() << " now has " << Toast.getYield() << " servings" << endl;
                    for (auto & ingredient : Toast.getIngredients()){
                        cout << ingredient.getItem().getName() << ": " << ingredient.getQuantity() << " " << ingredient.getItemMeasureUnit() << endl;
                    }
                    cout << endl;
                    break;
                }
            case 2:
                {
                    cout << "What ingredient are you changing quantity of: ";
                    cin >> userInput;
                    cout << endl;

                    string iName = userInput;

                    cout << "What quantity are you changing to: ";
                    cin >> userInput;
                    cout << endl;

                    float quantity = atof(userInput.c_str());

                    FoodItem item;

                    for (RecipeItem ingredient : Toast.getIngredients()){
                        if (ingredient.getItem().getName().compare(iName) == 0){
                            item = ingredient.getItem();
                        }
                    }

                    if (item.getName().compare("") == 0){
                        cout << "Not an ingredient in recipe\n" << endl;
                        break;
                    }

                    Toast.adjustIngredientAmount(item, quantity);

                    for (auto & ingredient : Toast.getIngredients()){
                        cout << ingredient.getItem().getName() << ": " << ingredient.getQuantity() << " " << ingredient.getItemMeasureUnit() << endl;
                    }
                    cout << endl;
                    break;
                }
            case 3:
                {
                    cout << "What ingredient are you swapping out: ";
                    cin >> userInput;
                    cout << endl;

                    string rName = userInput;

                    cout << "What ingredient are you swapping in (only \"jam\" exists): ";
                    cin >> userInput;
                    cout << endl;

                    string nName = userInput;

                    FoodItem nItem;

                    for (FoodItem food : inventory){
                        if (food.getName().compare(nName) == 0){
                            nItem = food;
                        }
                    }

                    if (nItem.getName().compare("") == 0){
                        cout << "Not an ingredient in inventory\n" << endl;
                        break;
                    }

                    for (auto & ingredient : Toast.getIngredients()){
                        if (ingredient.getItem().getName().compare(rName) == 0){
                            Toast.swapIngredient(nItem, ingredient);
                        }
                    }

                    for (auto & ingredient : Toast.getIngredients()){
                        cout << ingredient.getItem().getName() << ": " << ingredient.getQuantity() << " " << ingredient.getItemMeasureUnit() << endl;
                    }
                    cout << endl;
                    break;
                }
            case 4:
                {
                    break;
                }
            default:
                cout << "Invalid option\n" << endl;
        }
    }
}