/*
 * TouchScreenView.h
 */
#ifndef TOUCHSCREEN_VIEW_H
#define TOUCHSCREEN_VIEW_H

#include "View.h"
#include "Model.h"

class TouchScreenView : public View {
    
    private:
        const Model* model;
    
    public:
        TouchScreenView(Model *model);
        ~TouchScreenView();
        void setModel(Model *model);
        void display();
};
#endif