/**
 * @file TouchScreenView.cpp
 * @author Jared Anstett
 * @brief TouchScreenView class builds a GUI for users to interact
 * with the Freshcipes recipe and stock management application
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TouchScreenView.h"

/**
 * @brief Construct a new Touch Screen View:: Touch Screen View object
 * 
 * @param model 
 */
TouchScreenView::TouchScreenView(Model *model){
    this->model = model;
}

/**
 * @brief Destroy the Touch Screen View:: Touch Screen View object
 * 
 */
TouchScreenView::~TouchScreenView(){
    delete this;
}

/**
 * @brief setModel
 * 
 * @param model 
 */
void TouchScreenView::setModel(Model *model){
    this->model=model;
}

/**
 * @brief display() - displays content to be updated
 * by the controller
 * 
 */
void TouchScreenView::display(){

}