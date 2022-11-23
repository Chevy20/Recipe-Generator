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

    RecipeItem rBread(bread, 2, "slices");
    RecipeItem rButter(butter, 5, "ounces");

    vector<RecipeItem> recipe;
    recipe.push_back(rBread);
    recipe.push_back(rButter);

    map<string, int> nutri;

    Recipe Toast("Toast", recipe, nutri, 1);

    cout << "Change " << Toast.getRecipeName() << " serving size, starts at: " << Toast.getYield() << endl;

    string userInput;

    while (true){
        cout << "select new portions size: ";
        cin >> userInput;
        cout << endl;

        if (userInput.compare("exit") == 0){
            break;
        }

        int nServings = atoi(userInput.c_str());

        Toast.changeProportions(nServings);

        cout << Toast.getRecipeName() << " now has " << Toast.getYield() << " servings" << endl;
        vector<RecipeItem> ingredients = Toast.getIngredients();
        for (auto & ingredient : ingredients){
            cout << ingredient.getItem().getName() << ": " << ingredient.getQuantity() << " " << ingredient.getItemMeasureUnit() << endl;
        }
    }
}