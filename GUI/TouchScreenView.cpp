#inlclude "TouchScreenView.h"

TouchScreenView::TouchScreenView(const Model &model){
    this->model = model;
}

TouchScreenView::~TouchScreenView(){
    delete this;
}

void TouchScreenView::setModel(const Model &model){
    this->model=model;
}

void TouchScreenView::display(){

}