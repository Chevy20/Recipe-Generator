
#include "WebView.h"
using namespace Wt;

/*
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
*/

WebView::WebView(const WEnvironment &env): WApplication(env){
    WebView::name = "Freshcipes";
    setTitle(WebView::name);
    WebView::_content = 0;
    WebView::internalPathChanged().connect(this, &WebView::onInternalPathChange);

    WebView::header();
    WebView::home();
    WebView::sidebar();
    WebView::footer();
}

WContainerWidget* content(){
    if(WebView::_content == 0) {
        WebView::_content = new WContainerWidget(root());
        WebView::_content->setId("content");
    }
    return WebView::_content;
}

void WebView::onInternalPathChange() {
    content()->clear();
    if(internalPath()=="/"){
        home();
    }
    else if(internalPath()=="/page1"){
        page1();
    }
}

void WebView::header() {
    WContainerWidget* header = new WContainerWidget(root());
    header->setId("header");
    header->addWidget(new WText("<h1>" + WebView::name + "</h1>"));
}

void WebView::sidebar() {
    WContainerWidget* sidebar = new WContainerWidget(root());
    sidebar->setId("sidebar");
    sidebar->addWidget(new WText("Sidebar Information"));
}

void WebView::footer() {
    WContainerWidget* footer = new WContainerWidget(root());
    footer->setId("footer");
    footer->addWidget(new WText("Developed using C++/Wt"));
}

void WebView::home() {
    WText *t = new WText("<strong>Home</strong> content and a link to <a href='#/page1'>page1</a>");
    t->setInternalPathEncoding(true);
    content()->addWidget(t);

}

void WebView::page1() {
    content()->addWidget(new WText("<strong>Home</strong> content and a link to "));
    WAnchor* a = new WAnchor(WLink(WLink::InternalPath, "/"), "home", content());
}

WApplication* buildApp(const WEnvironment &env) {
    return new WebView::WebView(env);
}


int main(int argc, char** argv) {
    return WRun(argc, argv, &buildApp)
}