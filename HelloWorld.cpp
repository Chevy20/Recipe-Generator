#include <Wt/WApplication.h>
#include <Wt/WServer.h>

int main(int argc, char *argv[]){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env){
        auto app = std::make_unique<Wt::WApplication>(env);
        auto root = app->root();  //WContainerWidget *root (<div>)
        
        // add a new WText, using the addNew shorthand
        root->\addNew<Wt::WText>("Your name, please? ");

        Wt::WLineEdit* edit = root->addNew<Wt::WLineEdit>();
        auto btn = root ->addNew<Wt::WPushButton>("Greet me!");
        root->addNew<Wt::WBreak>();
        // Empty WText in Plain format (default is filtered XHTML)
        auto result = root->addNew<Wt::WText>();
        result -> setTextFormat(Wt::TextFormat::Plain);

        // Create a lambda function
        auto showGreeting = [edit, result]{
            result->setText(Wt::WString("Hello, {1}!").arg(edit->text()));
        };

        return app;
    });
}