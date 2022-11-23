
#include "test.hpp"
#include <memory>
#include<utility>

//using namespace std;

int main() {

    auto container = std::make_unqiue<Wt::WContainerWidget>();

    container->addNew<Wt::WText>("First widget");

    for(int i=0; i<3; ++i){
        container->addNew<Wt::WText>(Wt::WString("<p>Text {1}</p>").arg(i));
    }
}