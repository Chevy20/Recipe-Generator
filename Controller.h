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
    Controller();
    Controller(Model* model, View* view);
    ~Controller();
    bool updateModel();
    bool updateView();
    Model* getModel();
    View* getView();
    void setModel(Model* model);
    void setView(View* view);
    void registerObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify() ;
    auto eventHandler(std::string func);
	auto eventHandler(std::string func, auto item);
};

#endif
