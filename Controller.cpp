#include "Controller.h"

using namespace std;


/**
 * @author Nick Baesso
 * 
 * @brief Constructor - Sets the variables of this class.
 */
Controller::Controller() {
    this->model = NULL;
    this->view = NULL;
}


/**
 * @author Nick Baesso
 * 
 * @brief Constructor - Sets the variables of this class.
 * 
 * @param model The model that this controller communicates to.
 * @param view The view that controls this controller.
 */
Controller::Controller(Model* model, View* view) {
    this->model = model;
    this->view = view;
}


/**
 * @author Nick Baesso
 * 
 * @brief Destructor - Deletes the class variables of this controller.
 */
Controller::~Controller() {
    delete(this->model);
    delete(this->view);
}


/**
 * 
 * 
 * 
 */
bool Controller::updateModel() {
    
}


/**
 * 
 * 
 * 
 */
bool Controller::updateView() {
    
}


/**
 * @author Nick Baesso
 * 
 * @brief Returns the model.
 * 
 * @return The model connected to this controller.
 */
Model* Controller::getModel() {
    return this->model;
}


/**
 * @author Nick Baesso
 * 
 * @brief Returns the view.
 * 
 * @return The view connected to this controller.
 */
View* Controller::getView() {
    return this->view;
}


/**
 * @author Nick Baesso
 * 
 * @brief Sets the model connected to this controller.
 * 
 * @param model The model to connect.
 */
void Controller::setModel(Model* model) {
    this->model = model;
}


/**
 * @author Nick Baesso
 * 
 * @brief Sets the view connected to this controller.
 * 
 * @param model The view to connect.
 */
void Controller::setView(View* view) {
    this->view = view;
}


/**
 * @author Nick Baesso
 * 
 * @brief Registers/attaches an observer onto this controller.
 * 
 * @param observer Observer to attach.
 */
void Controller::registerObserver(Observer* observer) {
    this->observerList.push_back(observer);
}


/**
 * @author Nick Baesso
 * 
 * @brief Removes an observer from this controller.
 * 
 * @param observer Observer to remove.
 */
void Controller::removeObserver(Observer* observer) {
    for(int n = 0; n < this->observerList.size(); n++)
        if(this->observerList[n] == observer)
            this->observerList.erase(this->observerList.begin() + n);
}


/**
 * @author Nick Baesso
 * 
 * @brief Notifies/updates all the observers.
 */
void Controller::notify(){
    for(int n = 0; n < this->observerList.size(); n++)
        observerList[n].update(this);
}


/**
 * @author Nick Baesso
 * 
 * @brief Takes a function from the view and calls the related model function.
 * 
 * @param func The desired function. Is case sensitive and must be without any parenthesis.
 * 
 * @return The corresponding return value of the desired function from the model.
 */
auto Controller::eventHandler(std::string func) {
    switch(func) {
        case "getDBConnection":
            return this->model.getDBConnection();
        case "getDbContext":
            return this->model.getDbContext();
        case "queryAllFoodItems":
            return this->model.queryAllFoodItems();
        case "checkForExpiredFood":
            return this->model.checkForExpiredFood();
        case "checkForLowStock":
            return this->model.checkForLowStock();
    }

    return NULL;
}


/**
 * @author Nick Baesso
 * 
 * @brief Takes a function from the view and calls the related model function. These are functions with a parameter.
 * 
 * @param func The desired function. Is case sensitive and must be without any parenthesis.
 * @param item The parameter of the desired function.
 * 
 * @return The corresponding return value of the desired function from the model.
 */
auto Controller::eventHandler(std::string func, auto item) {
    switch (func) {
    case "addFoodItem":
        return this->model.addFoodItem(item);
    case "removeFoodItem":
        return this->model.removeFoodItem(item);
    case "modifyFoodItem":
        return this->model.modifyFoodItem(item);
    case "querySingleFoodItem":
        return this->model.querySingleFoodItem(item);
    }

    return NULL;
}
