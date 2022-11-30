/*
 * TerminalView.h
 */
#ifndef TERMINAL_VIEW_H
#define TERMINAL_VIEW_H

#include "View.h"
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

class TerminalView : public View {
    
    private:
        Model* model;
        bool isDigit(const std::string& input);
        bool check(std::string input);
        bool checkRecipe(std::string input, std::vector<Recipe> recipieList);
        bool checkDate(std::string input);
        void printFoodItem(FoodItem item);

    public:
        TerminalView(Model *model);
        ~TerminalView();
        virtual void setModel(Model *model);
        virtual Model* getModel();
        virtual void display();
};
#endif
