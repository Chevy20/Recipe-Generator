#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "Model.h"
#include "View.h"
#include "Observer.h"

class Controller {
private:
    Model *model;
    View *view;
    std::vector<Observer*> observerList;
public:
    Controller();
    ~Controller();
    bool updateModel();
    bool updateView();
    Model getModel();
    View getView();
    void setModel(Model model);
    void setView(View view);
    void registerObserver();
    void removeObserver();
    virtual void notify();
    void eventHandler();
};

#endif