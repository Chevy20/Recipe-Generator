/*
 * View.h
 */
#ifndef VIEW_H
#define VIEW_H

#include "../Model.h"

class View {
    
    private:
        Model model;
    
    public:
        View(const Model &model);
        ~View();
        void setModel(Model &model);
        void display();
};
#endif

