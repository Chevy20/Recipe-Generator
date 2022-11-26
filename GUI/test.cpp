
#include "test.hpp"
#include <memory>
#include <utility>

using namespace std;

WebView::WebView(const Wt::WEnvironment& env) : Wt::WApplication(env){

    appName_ = "Freshcipes WebView";
    setTitle(appName_);
    content_ = 0;
    // internalPathChanged().connect(this, &WebView::onInternalPathChange);

    home();
    root()->addWidget(std::unique_ptr<Wt::WWidget>(header()));
    root()->addWidget(std::unique_ptr<Wt::WWidget>(sidebar()));
    root()->addWidget(std::unique_ptr<Wt::WWidget>(content()));
    root()->addWidget(std::unique_ptr<Wt::WWidget>(footer()));
    // root()->addWidget(std::make_unique<Wt::WText>("Your name, please? "));
    // nameEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    // Wt::WPushButton *button = root()->addWidget(std::make_unique<Wt::WPushButton>("Greet me."));
    // root()->addWidget(std::make_unique<Wt::WBreak>());
    // greeting_ = root()->addWidget(std::make_unique<Wt::WText>());
    // auto greet = [this]{
    //   greeting_->setText("Hello there, " + nameEdit_->text());
    // };
    // button->clicked().connect(greet);

}

Wt::WContainerWidget* WebView::content() {
    if (content_ == 0) {
        content_ = new Wt::WContainerWidget();
        content_->setId("content");
    }
    return content_;
}

// void WebView::onInternalPathChange() {
//     WebView::content()->clear();
//     if(internalPath()=="/"){
//         WebView::home();
//     }
//     else if(internalPath()=="/page1"){
//         WebView::page1();
//     }
// }

Wt::WContainerWidget* WebView::header() {
    Wt::WContainerWidget* header = new Wt::WContainerWidget();
    header->setId("header");
    header->addWidget(std::make_unique<Wt::WText>("<h1>" + appName_ + "</h1>"));
    return header;
}

Wt::WContainerWidget* WebView::sidebar() {
    Wt::WContainerWidget* sidebar = new Wt::WContainerWidget();
    sidebar->setId("sidebar");
    sidebar->addWidget(std::make_unique<Wt::WText>("Sidebar Information"));
    return sidebar;
}

Wt::WContainerWidget* WebView::footer() {
    Wt::WContainerWidget* footer = new Wt::WContainerWidget();
    footer->setId("footer");
    footer->addWidget(std::make_unique<Wt::WText>("Developed using C++/Wt"));
    return footer;
}

void WebView::home() {
    Wt::WText *t = new Wt::WText("<strong>Home</strong> content and a link to <a href='#/page1'>page1</a>");
    t->setInternalPathEncoding(true);
    content()->addWidget(std::unique_ptr<Wt::WText>(t));
}

// void page1() {
//     content()->addWidget(new Wt::WText("<strong>Home</strong> content and a link to "));
//     Wt::WAnchor* a = new Wt::WAnchor(Wt::WLink(Wt::WLink::internalPath, "/"), "home", content());
// }


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
