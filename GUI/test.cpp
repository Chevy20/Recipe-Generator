
#include "test.hpp"


using namespace Wt;



WebView::WebView(const WEnvironment& env) : WApplication(env){
   
    // root()->addWidget(std::make_unique<Wt::WText>("Your name, please? "));
    // nameEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    // Wt::WPushButton *button = root()->addWidget(std::make_unique<Wt::WPushButton>("Greet me."));
    // root()->addWidget(std::make_unique<Wt::WBreak>());
    // greeting_ = root()->addWidget(std::make_unique<Wt::WText>());
    // auto greet = [this]{
    //   greeting_->setText("Hello there, " + nameEdit_->text());
    // };
    // button->clicked().connect(greet);

    appName_ = "Freshcipes WebView";
    setTitle(appName_);
    content_ = 0;
    // internalPathChanged().connect(this, &WebView::onInternalPathChange);
    
    // Sets the web theme to Bootstrap 5
    this->setTheme(std::make_shared<WBootstrap5Theme>());

    home();
    root()->addWidget(std::unique_ptr<WWidget>(header()));
    root()->addWidget(std::unique_ptr<WWidget>(sidebar()));
    root()->addWidget(std::unique_ptr<WWidget>(content()));
    root()->addWidget(std::unique_ptr<WWidget>(footer()));



    WNavigationBar* nav = root()->addWidget(std::make_unique<WNavigationBar>());
    nav->setMargin(WLength(5));
    nav->setVerticalAlignment(AlignmentFlag::Middle);

    auto pb1 = std::make_unique<WPushButton>();
    nav->setMargin(WLength(20));

    nav->addWidget(std::make_unique<WText>("<a href='/add-item-to-stock'>Add Item</a>"));
    nav->addWidget(std::make_unique<WPushButton>("TEST2"));
    nav->addSearch(std::make_unique<WLineEdit>());
    nav->show();    
}

WContainerWidget* WebView::content() {
    if (content_ == 0) {
        content_ = new WContainerWidget();
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

WContainerWidget* WebView::header() {
    WContainerWidget* header = new WContainerWidget();
    header->setId("header");
    header->addWidget(std::make_unique<WText>("<h1>" + appName_ + "</h1>"));
    return header;
}

// WNavigationBar* WebView::navbar() {

// }

WContainerWidget* WebView::sidebar() {
    WContainerWidget* sidebar = new WContainerWidget();
    sidebar->setId("sidebar");
    sidebar->addWidget(std::make_unique<WText>("Sidebar Information"));
    return sidebar;
}

Wt::WContainerWidget* WebView::footer() {
    Wt::WContainerWidget* footer = new WContainerWidget();
    footer->setId("footer");
    footer->addWidget(std::make_unique<WText>("Developed using C++/Wt"));
    return footer;
}

void WebView::home() {
    Wt::WText *t = new Wt::WText("<strong>Home</strong> content and a link to <a href='/page1'>page1</a>");
    t->setInternalPathEncoding(true);
    content()->addWidget(std::unique_ptr<WText>(t));
}



// void WebView::page1() {
//     content_->addWidget(std::make_unique<WText>("<strong>Home</strong> content and a link to "));
//     Wt::WAnchor* a = new WAnchor();
//     a->addWidget(std::make_unique<WLink>(internalPath(), "/"), "home", content());
// }

// Navigate the internal pages of the GUI
void WebView::handleInternalPath(const std::string &internalPath){
    if(internalPath == "/add-item-to-stock"){}
    else if(internalPath == "/"){}
    else if(internalPath == "/"){}
    else if(internalPath == "/"){}
    else if(internalPath == "/"){}
    else if(internalPath == "/"){}
    else if(internalPath == "/"){}
    else{
        WApplication::instance()->setInternalPath("/", true);
    }
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
