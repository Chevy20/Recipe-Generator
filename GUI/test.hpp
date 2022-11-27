/*
 * Test GUI
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WBreak.h>
#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WServer.h>
#include <Wt/WFlags.h>
#include <Wt/WTemplate.h>
#include <Wt/WTheme.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WString.h>
#include <Wt/WLink.h>
#include <Wt/WAnchor.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WMenu.h>
#include <Wt/WMenuItem.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WTheme.h>
#include <Wt/WLink.h>

#define INSERT_ITEM_TXT = "Insert Item"
#define INSERT_ITEM_TXT = "Insert Item"
#define INSERT_ITEM_TXT = "Insert Item"
#define INSERT_ITEM_TXT = "Insert Item"

class WebView : public Wt::WApplication {
    public:
        WebView(const Wt::WEnvironment& env);
        static int launch(int argc, char** argv);
        Wt::WContainerWidget* content();
        void onInternalPathChange();
        Wt::WContainerWidget* header();
        Wt::WContainerWidget* sidebar();
        Wt::WContainerWidget* footer();
        void home();
        void page1();
        void handleInternalPath(const std::string &internalPath);  // for navigation
        void buildLayout(); 

    private:
        enum commands{ INSERT, DELETE, MODIFY, FIND_STOCK_ITEM, FIND_STOCK_ALL, RECIPE_BY_ITEM, RECIPE_FOR_ALL, QUIT };
        std::string appName_;
        Wt::WContainerWidget *content_;
        
        Wt::WLineEdit *nameEdit_;
        Wt::WText *greeting_;
    
    protected: 
        const std::map<commands, std::string> cmd;
};

#endif