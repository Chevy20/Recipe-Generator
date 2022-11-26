#inlclude "TerminalView.h"

TerminalView::TerminalView(const Model &model){
    this->model = model;
}

TerminalView::~TerminalView(){
    delete this;
}

void TerminalView::setModel(const Model &model){
    this->model=model;
}

void TerminalView::display(){

}




