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

        root->addWidget(std::make_unique<Wt::WLineEdit>("Your name, please? "));
        auto edit = root->addNew<Wt::WLineEdit>();
        auto btn = root->addNew<Wt::WPushButton>("Greet me!");
        root->addNew<Wt::WBreak>();
        auto result = root->addNew<Wt::WText>();
        result->setTextFormat(Wt::TextFormat::Plain);
        root->addWidget(Wt::cpp14::make_unique<Wt::WTable>());

        auto showGreeting = [edit, result]{
            result->setText(Wt::WString("Hello, {1}!").arg(edit->text()));
        };

        edit->enterPressed().connect(showGreeting);
        btn->clicked().connect(showGreeting);

        // Create an anchor that links to a URL through an image.
        Wt::WLink link = Wt::WLink("https://localhost:8080/test");
        link.setTarget(Wt::LinkTarget::NewWindow);

        std::unique_ptr<Wt::WAnchor> anchor = std::make_unique<Wt::WAnchor>(link);
        anchor->addNew<Wt::WImage>(Wt::WLink("https://www.emweb.be/css/emweb_small.png"));

        Wt::WTable *table=addWidget(std::make_unique<Wt::WTable>());
        table->elementAt(0, 0)->addWidget(std::make_unique<Wt::WText>("Item @ row 0, column 0"));
        table->elementAt(0, 1)->addWidget(std::make_unique<Wt::WText>("Item @ row 0, column 1"));
        table->elementAt(1, 0)->addWidget(std::make_unique<Wt::WText>("Item @ row 1, column 0"));
        table->elementAt(1, 1)->addWidget(std::make_unique<Wt::WText>("Item @ row 1, column 1"));
        Wt::WTableCell *cell = table->elementAt(2, 0);
        cell->addWidget(std::make_unique<Wt::WText>("Item @ row 2"));
        cell->setColumnSpan(2);
        root->addWidget(std::make_unique(*table));

        return app;
    });
}