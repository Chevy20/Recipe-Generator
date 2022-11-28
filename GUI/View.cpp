#include <Model.h>

class View {
    
    private:
        Model* model;
    
    public:
        View(const Model &model) {
            this->model = model;
        }
        void setModel(const Model &model);
        virtual void display()=0;
};