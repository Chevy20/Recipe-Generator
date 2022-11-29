/*
 * TerminalView.h
 */
#ifndef TERMINAL_VIEW_H
#define TERMINAL_VIEW_H

#include "View.h"
#include "Model.h"

class TerminalView : public View {
    
    private:
        const Model* model;
    
    public:
        TerminalView(Model *model);
        ~TerminalView();
        void setModel(Model *model);
        void display();
};
#endif
