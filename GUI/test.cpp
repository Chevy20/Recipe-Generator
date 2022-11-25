
#include "test.hpp"
#include <memory>
#include<utility>

using namespace std;

WebView::WebView(const Wt::WEnvironment& env) : Wt::WApplication(env){

    appName_ = "Freshcipes WebView";
    setTitle(appName_);
    _content = 0;
    //internalPathChanged().connect(this, &WebView::onInternalPathChange);

    WebView::header();
    //WebView::home();
    WebView::sidebar();
    // WebView::footer();

    root()->addWidget(std::make_unique<Wt::WText>("Your name, please? "));
    nameEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    Wt::WPushButton *button = root()->addWidget(std::make_unique<Wt::WPushButton>("Greet me."));
    root()->addWidget(std::make_unique<Wt::WBreak>());
    greeting_ = root()->addWidget(std::make_unique<Wt::WText>());
    auto greet = [this]{
      greeting_->setText("Hello there, " + nameEdit_->text());
    };
    button->clicked().connect(greet);

}

Wt::WContainerWidget* WebView::content() {
    if (_content == 0) {
        _content = new Wt::WContainerWidget();
        _content->setId("content");
    }
    return _content;
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

void WebView::header() {
    Wt::WContainerWidget* header = new Wt::WContainerWidget();
    header->setId("header");
    header->addWidget(std::make_unique<Wt::WText>("<h1>" + appName_ + "</h1>"));
}

void WebView::sidebar() {
    Wt::WContainerWidget* sidebar = new Wt::WContainerWidget();
    sidebar->setId("sidebar");
    sidebar->addWidget(std::make_unique<Wt::WText>("Sidebar Information"));
}

// void WebView::home() {
//     Wt::WText *t = new Wt::WText("<strong>Home</strong> content and a link to <a href='#/page1'>page1</a>");
//     t->setInternalPathEncoding(true);
//     content()->addWidget(t);
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
