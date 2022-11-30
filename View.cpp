/**
 * @file View.cpp
 * @author Jared Anstett
 * @brief View is an abstract class meant to be inherited by derived
 * view classes
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Model.h"

/**
 * @brief View is an abstract class meant to be inherited by derived
 * view classes
 */
class View {
    
    private:
        const Model* model;
    
    public:
        View(Model *model) {
            this->model = model;
        }
};