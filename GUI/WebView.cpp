
#include "WebView.h"
using namespace Wt;


int main(int argc, char *argv[]) {
    return Wt::WRun(argc, argv, [](const WEnvironment &env){
        
        auto app = std::make_unique<WApplication>(env);
        auto root = app->root();

        root->setContentAlignment(AlignmentFlag::Center);
        
        root->addWidget(std::make_unique<WLineEdit>("Item name: "));
        root->addNew<WBreak>();

        root->addWidget(std::make_unique<WLineEdit>("Measurement Type: "));
        root->addNew<Wt::WBreak>();

        root->addWidget(std::make_unique<WLineEdit>("Item Qty: "));
        root->addNew<Wt::WBreak>();

        root->addWidget(std::make_unique<WLineEdit>("Date Purchased: "));
        root->addNew<Wt::WBreak>();

        root->addWidget(std::make_unique<WLineEdit>("Expiry Date: "));
        root->addNew<Wt::WBreak>();

        root->addWidget(std::make_unique<WLineEdit>("Date Threshold: "));
        root->addNew<Wt::WBreak>();

        auto edit = root->addNew<WLineEdit>();
        auto btn = root->addNew<WPushButton>("Find Recipes");
        
        root->addNew<Wt::WBreak>();
        auto result = root->addNew<WText>();
        result->setTextFormat(TextFormat::Plain);

        
        auto showGreeting = [edit, result]{
            result->setText(Wt::WString("Look up {1}!").arg(edit->text()));
        };

        edit->enterPressed().connect(showGreeting);
        btn->clicked().connect(showGreeting);


        return app;
    });
}