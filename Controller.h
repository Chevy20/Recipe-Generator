#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "Model.h"
#include "View.h"
#include "Observer.h"

class Controller {
private:
    Model* model;
    View* view;
    std::vector<Observer*> observerList;
public:
    /**
     * @author Nick Baesso
     * 
     * @brief Constructor - Sets the variables of this class.
     */
    Controller();
    /**
     * @author Nick Baesso
     * 
     * @brief Constructor - Sets the variables of this class.
     * 
     * @param model The model that this controller communicates to.
     * @param view The view that controls this controller.
     */
    Controller(Model* model, View* view);
    /**
     * @author Nick Baesso
     * 
     * @brief Destructor - Deletes the class variables of this controller.
     */
    ~Controller();
    bool updateModel();
    bool updateView();
    /**
     * @author Nick Baesso
     * 
     * @brief Returns the model.
     * 
     * @return The model connected to this controller.
     */
    Model* getModel();
    /**
     * @author Nick Baesso
     * 
     * @brief Returns the view.
     * 
     * @return The view connected to this controller.
     */
    View* getView();
    /**
     * @author Nick Baesso
     * 
     * @brief Sets the model connected to this controller.
     * 
     * @param model The model to connect.
     */
    void setModel(Model* model);
    /**
     * @author Nick Baesso
     * 
     * @brief Sets the view connected to this controller.
     * 
     * @param model The view to connect.
     */
    void setView(View* view);
    /**
     * @author Nick Baesso
     * 
     * @brief Registers/attaches an observer onto this controller.
     * 
     * @param observer Observer to attach.
     */
    void registerObserver(Observer* observer);
    /**
     * @author Nick Baesso
     * 
     * @brief Removes an observer from this controller.
     * 
     * @param observer Observer to remove.
     */
    void removeObserver(Observer* observer);
    /**
     * @author Nick Baesso
     * 
     * @brief Notifies/updates all the observers.
     */
    void notify() ;
    /**
     * @author Nick Baesso
     * 
     * @brief Takes a function from the view and calls the related model function.
     * 
     * @param func The desired function. Is case sensitive and must be without any parenthesis.
     * 
     * @return The corresponding return value of the desired function from the model.
     */
    auto eventHandler(std::string func);
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
    auto eventHandler(std::string func, auto item);
};

#endif
