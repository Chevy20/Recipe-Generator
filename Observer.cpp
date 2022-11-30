#include "Observer.h"
using namespace std;


/**
 * @author Nick Baesso
 * 
 * @brief Constructor - Sets the variables of this class.
 * 
 * @param controller The controller that is being observed.
 */
Observer::Observer(Controller* controller) {
    controller = controller;
    controller->registerObserver()
}


/**
 * @author Nick Baesso
 * 
 * @brief Destructor - Deletes the class variables of this controller.
 */
Observer::~Observer() override {

}

/**
 * @author Nick Baesso
 * 
 * @brief Updates this observer with the current controller.
 * 
 * @param controller The current controller to update this observer with.
 */
void Observer::update(Controller* controller) override {
    this->controller = controller;
}
