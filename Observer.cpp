#include "Observer.h"
using namespace std;


/**
 * Constructor - Sets the variables of this class.
 * 
 * @param controller The controller that is being observed.
 */
Observer::Observer(Controller* controller) {
    controller = controller;
    controller->registerObserver()
}


/**
 * Destructor - Deletes the class variables of this controller.
 */
Observer::~Observer() override {

}

/**
 * Updates this observer with the current controller.
 * 
 * @param controller The current controller to update this observer with.
 */
void Observer::update(Controller* controller) override {
    this->controller = controller;
}
