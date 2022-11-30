#ifndef OBSERVER_H
#define OBSERVER_H

#include "Controller.h"

class Observer {
private:
    Controller* controller;
public:
    /**
     * @author Nick Baesso
     * 
     * @brief Destructor - Deletes the class variables of this controller.
     */
    virtual ~Observer();
    /**
     * @author Nick Baesso
     * 
     * @brief Updates this observer with the current controller.
     * 
     * @param controller The current controller to update this observer with.
     */
    virtual void update(Controller* controller) = 0;
protected:
    /**
     * @author Nick Baesso
     * 
     * @brief Constructor - Sets the variables of this class.
     * 
     * @param controller The controller that is being observed.
     */
    Observer(Controller* controller);
};

#endif
