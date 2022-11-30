/**
 * @file TouchScreenView.h
 * @author Jared Anstett
 * @brief TouchScreenView class builds a GUI for users to interact
 * with the Freshcipes recipe and stock management application
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOUCHSCREEN_VIEW_H
#define TOUCHSCREEN_VIEW_H

#include "View.h"
#include "Model.h"

/**
 * @brief TouchScreenView class builds a GUI for users to interact
 * with the Freshcipes recipe and stock management application
 * 
 */
class TouchScreenView : public View {
    
    private:
        const Model* model;
    
    public:
        TouchScreenView(Model *model);
        ~TouchScreenView();
        void setModel(Model *model);
        void display();
};
#endif