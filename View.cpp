#include "Model.h"

class View {
    
    private:
        const Model* model;
    
    public:
        View::View(Model *model) {
            this->model = model;
        }
};