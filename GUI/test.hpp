/*
 * Test GUI
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WBreak.h>
#include <Wt/WApplication.h>
#include <Wt/WServer.h>
#include <Wt/WFlags.h>
#include <Wt/WTemplate.h>
#include <Wt/WTheme.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WString.h>

class WebView : public Wt::WApplication{
    public:
        WebView(const Wt::WEnvironment& env);
        static int launch(int argc, char** argv);
        Wt::WContainerWidget* content();
        void onInternalPathChange();
        void header();
        void sidebar();
        void footer();
        void home();
        void page1();

    private:
        std::string appName_;
        Wt::WContainerWidget* _content;
        
        Wt::WLineEdit *nameEdit_;
        Wt::WText *greeting_;
};

#endif