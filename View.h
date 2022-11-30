/**
 * @file View.h
 * @author Jared Anstett
 * @brief View is an abstract class meant to be inherited by derived
 * view classes
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VIEW_H
#define VIEW_H

#include "Model.h"

/**
 * @brief View is an abstract class meant to be inherited by derived
 * view classes
 * 
 */
class View {
    
    private:
        const Model* model;
    
    public:
        virtual Model* getModel()=0;
        virtual void setModel(Model *model)=0;
        virtual void display()=0;
};
#endif

