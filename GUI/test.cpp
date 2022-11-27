
#include "test.hpp"
#include "Wt/WPanel.h"
#include "Wt/WLink.h"
#include "Wt/WPopupMenu.h"
#include "Wt/WMessageBox.h"
#include <iostream>

using namespace Wt;

WebView::WebView(const WEnvironment& env) : WApplication(env){

    appName_ = "Freshcipes WebView";
    setTitle(appName_);
    content_ = 0;
    // internalPathChanged().connect(this, &WebView::onInternalPathChange);
    
    // Sets the web theme to Bootstrap 5
    this->setTheme(std::make_shared<WBootstrap5Theme>());

    home();

    /* NAVBAR **********************************************************/
    auto nav_container = root()->addWidget(std::make_unique<WContainerWidget>());
    //Create nav bar
    WNavigationBar *navigation = nav_container->addNew<WNavigationBar>();
    navigation->setResponsive(true);
    navigation->addStyleClass("navbar-light bg-light");
    navigation->setTitle("Freschipes", "/");

    WStackedWidget *contentStack = nav_container->addNew<WStackedWidget>();
    contentStack->addStyleClass("contents");
    
    // Setup a Left-aligned menu.
    auto leftMenu = std::make_unique<Wt::WMenu>(contentStack);
    auto leftMenu_ = navigation->addMenu(std::move(leftMenu));

    auto searchResult = std::make_unique<Wt::WText>("Buy or Sell... Bye!");
    auto searchResult_ = searchResult.get();

    leftMenu_->addItem("Home", std::make_unique<Wt::WText>("There is no better place!"))
        ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));
    leftMenu_->addItem("Stock", std::make_unique<Wt::WText>("There is no better place!"))
        ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/add-item-to-stock"));
    leftMenu_->addItem("Recipes", std::make_unique<Wt::WText>("Delete stock item"))
        ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/delete-item-from-stock"));



    leftMenu_->addItem("TEST", std::move(searchResult));
    leftMenu_->addStyleClass("me-auto");

    // Add a Search control.
    auto editPtr = std::make_unique<Wt::WLineEdit>();
    auto edit = editPtr.get();
    edit->setPlaceholderText("Enter a search item");

    edit->enterPressed().connect([=] {
    leftMenu_->select(2); // is the index of the "Sales"
    searchResult_->setText(Wt::WString("Nothing found for {1}.")
                                    .arg(edit->text()));
    });

    navigation->addSearch(std::move(editPtr));

    // Setup a Right-aligned menu.
    auto rightMenu = std::make_unique<Wt::WMenu>();
    auto rightMenu_ = navigation->addMenu(std::move(rightMenu));

    // Create a popup submenu for the Help menu.
    auto popupPtr = std::make_unique<Wt::WPopupMenu>();
    auto popup = popupPtr.get();
    popup->addItem("Contents");
    popup->addItem("Index");
    popup->addSeparator();
    popup->addItem("About");

    popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
        auto messageBox = popup->addChild(
                std::make_unique<Wt::WMessageBox>
                ("Help",
                Wt::WString("<p>Showing Help: {1}</p>").arg(item->text()),
                Wt::Icon::Information,
                Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            popup->removeChild(messageBox);
        });

        messageBox->show();
    });

    auto item = std::make_unique<Wt::WMenuItem>("Help");
    item->setMenu(std::move(popupPtr));
    rightMenu_->addItem(std::move(item));

    
    /* END NAVBAR **********************************************************/


    // root()->addWidget(std::unique_ptr<WWidget>(header()));
    // root()->addWidget(std::unique_ptr<WWidget>(sidebar()));
    // root()->addWidget(std::unique_ptr<WWidget>(content()));
    // root()->addWidget(std::unique_ptr<WWidget>(footer()));
    
    // handleInternalPath(path);

    
}

WContainerWidget* WebView::content() {
    if (content_ == 0) {
        content_ = new WContainerWidget();
        content_->setId("content");
    }
    return content_;
}

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
    if(internalPath == "/add-item-to-stock"){ std::cerr << "HELLO IM HERE"; }
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
