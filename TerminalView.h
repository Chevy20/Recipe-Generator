/**
 * @file TerminalView.h
 * @author Matthew Cheverie
 * @brief TerminalView header file. This file contains the definitions for the terminal view class.
 * It inherits View class
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
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
/**
 * @brief This class contains the TerminalView object inherited from the View class.  It is responsible for the front end functionallity on the terminalApplication.
 * @author Matthew Cheverie
 */

class TerminalView : public View {
    
    private:
        Model* model; /**< Model*: the pointer to reference the model object needed to interface with the backend.*/

    
        /**
         * @brief This function will check if the given input string is a digit. Ignores '.' to allow for floats
         * @param input The input string
         * @author Matthew Cheverie
         * @return true if digit, false if not. 
         */
        bool isDigit(const std::string& input); 

        /**
         * @brief Checks if a given input will be accepted when the user is prompted to enter a command
         * @param input the input string
         * @author Matthew Cheverie
         * @return true if valid input, false it not
         */
        bool check(std::string input);  

         /**
         * @brief Checks if the input to select a recipe to cook is valid
         * @param input the input string
         * @param recipieList the list of recipe objects
         * @author Matthew Cheverie
         * @return true if valid recipe input, false if not
         */
        bool checkRecipe(std::string input, std::vector<Recipe> recipieList);

         /**
         * @brief check to see if the date inputed is valid
         * @param input the input string
         * @author Matthew Cheverie
         * @return true if valid date, false if not
         */
        bool checkDate(std::string input);

         /**
         * @brief  prints out a FoodItems attributes to the console in a styleized way.
         * @param item The food item object to be printed
         * @author Matthew Cheverie
         */
        void printFoodItem(FoodItem item);

    public:

         /**
         * @brief constructor for the Terminalview
         * @param model The pointer object that points to a model object used to interface with the backend
         * @author Matthew Cheverie
         */
        TerminalView(Model *model);

         /**
         * @brief Destructor for TerminalView
         * @author Matthew Cheverie
         */
        ~TerminalView();

         /**
         * @brief setter function for the model pointer. Inherited from View
         * @param model the new model object to be set
         * @author Matthew Cheverie
         */
        virtual void setModel(Model *model);

         /**
         * @brief Getter function for the model pointer. Inherited from View
         * @author Matthew Cheverie
         */
        virtual Model* getModel();

         /**
         * @brief Function to display the view. Inherited from View
         * @author Matthew Cheverie
         */
        virtual void display();
};
#endif
