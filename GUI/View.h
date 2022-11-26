/*
 * View.h
 */
#ifndef VIEW_H
#define VIEW_H

#include "../Model.h"

class View {
    
    private:
        Model* model;
    
    public:
        View(const Model &model);
        virtual ~View();
        virtual void setModel(const Model &model)=0;
        virtual void display()=0;
};
#endif

