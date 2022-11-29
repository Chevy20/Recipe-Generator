#ifndef OBSERVER_H
#define OBSERVER_H

#include "Controller.h"

class Observer {
private:
    Controller& controller;
public:
    virtual ~Observer();
    virtual void update(Controller* controller) = 0;
protected:
    Observer();
};

#endif
