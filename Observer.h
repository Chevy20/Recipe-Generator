#ifndef OBSERVER_H
#define OBSERVER_H

#include "Controller.h"

class Observer {
private:
    Controller& controller;
public:
    Observer() {};
    ~Observer() {};
    virtual void update(Controller* controller) = 0;
};

#endif