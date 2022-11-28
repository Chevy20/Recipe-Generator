
#include "WebView.h"
using namespace Wt;


WebView::WebView(const WEnvironment& env) : WApplication(env){
    
    View::View(new Model());

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


}


/**
 * Launch the app
*/
int WebView::launch(int argc, char** argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return std::make_unique<WebView>(env);
    });
}

int main(int argc, char** argv){
    WebView::launch(argc, argv);
}