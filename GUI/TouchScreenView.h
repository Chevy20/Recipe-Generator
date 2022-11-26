/*
 * TouchScreenView.h
 */
#ifndef TOUCHSCREEN_VIEW_H
#define TOUCHSCREEN_VIEW_H

#include "../Model.h"

class TouchScreenView : public View {
    
    private:
        Model* model;
    
    public:
        TouchScreenView(const Model &model);
        ~TouchScreenView();
        void setModel(const Model &model);
        void display();
};
#endif