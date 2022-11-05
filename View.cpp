#include <Model.h>

class View {
    
    private:
        Model model;
    
    public:
        View(const Model &model) {
            this->model = model;
        }
};