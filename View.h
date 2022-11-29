/*
 * View.h
 */
#ifndef VIEW_H
#define VIEW_H

#include "Model.h"

class View {
    
    private:
        const Model* model;
    
    public:
        virtual Model* getModel()=0;
        virtual void setModel(Model *model)=0;
        virtual void display()=0;
};
#endif

