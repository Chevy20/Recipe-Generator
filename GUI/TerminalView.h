/*
 * TerminalView.h
 */
#ifndef TERMINAL_VIEW_H
#define TERMINAL_VIEW_H

#include "../Model.h"

class TerminalView : public View {
    
    private:
        Model* model;
    
    public:
        TerminalView(const Model &model);
        ~TerminalView();
        void setModel(const Model &model);
        void display();
};
#endif
