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
        bool isDigit(const std::string& input);

    public:
        TerminalView(Model *model);
        ~TerminalView();
        void setModel(Model *model);
        void display();
};
#endif
