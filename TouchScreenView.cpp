#include "TouchScreenView.h"

TouchScreenView::TouchScreenView(Model *model){
    this->model = model;
}

TouchScreenView::~TouchScreenView(){
    delete this;
}

void TouchScreenView::setModel(Model *model){
    this->model=model;
}

void TouchScreenView::display(){

}