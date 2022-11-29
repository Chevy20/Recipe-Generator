#include "TerminalView.h"

TerminalView::TerminalView(Model *model){
    this->model = model;
}

TerminalView::~TerminalView(){
    delete this;
}

void TerminalView::setModel(Model *model){
    this->model=model;
}

void TerminalView::display(){

}




