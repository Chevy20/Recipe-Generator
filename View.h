/***
 * View.h
*/
#include<Model.h>

class View {
    
    private:
        Model model;
    
    public:
        View(const Model &model) {};
        void setModel(Model &model){};
        void display();
};

