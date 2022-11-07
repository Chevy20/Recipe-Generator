#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>
#include <Wt/WServer.h>
#include <Wt/WString.h>
#include <Wt/WLink.h>


class WebView : Wt::WApplication
{
    public:
        WebView(const Wt::WEnvironment& env);

    private:
        Wt::WTable *table;
        
};


int main(int argc, char *argv[]) {
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env){
        
        auto app = std::make_unique<Wt::WApplication>(env);
        auto root = app->root();

        root->addWidget(std::make_unique<Wt::WLineEdit>("Recipe items: "));
        root->addNew<Wt::WBreak>();

        auto edit = root->addNew<Wt::WLineEdit>();
        auto btn = root->addNew<Wt::WPushButton>("Find Recipes");
        
        root->addNew<Wt::WBreak>();
        auto result = root->addNew<Wt::WText>();
        result->setTextFormat(Wt::TextFormat::Plain);

        root->addWidget(Wt::cpp14::make_unique<Wt::WTable>());

        auto showGreeting = [edit, result]{
            result->setText(Wt::WString("Look up items {1}!").arg(edit->text()));
        };

        edit->enterPressed().connect(showGreeting);
        btn->clicked().connect(showGreeting);

        // Create an anchor that links to a URL through an image.
        Wt::WLink link = Wt::WLink("https://localhost:8080/test");
        link.setTarget(Wt::LinkTarget::NewWindow);

        std::unique_ptr<Wt::WAnchor> anchor = std::make_unique<Wt::WAnchor>(link);
        anchor->addNew<Wt::WImage>(Wt::WLink("https://www.emweb.be/css/emweb_small.png"));


        return app;
    });
}