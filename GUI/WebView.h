/*
 * View.h
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

#include "View.h"
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

class TouchScreenView : public View {
    
    private:
        Model* model;
    
    public:
        TouchScreenView(const Model &model);
        ~TouchScreenView();
        void setModel(const Model &model);
        void display();
};


class WebView : public Wt::WApplication, public View
{
private:
    Model* model;
    std::string name;  //app name
    Wt::WContainerWidget* _content;

    Wt::WText        *title_;
    Wt::WText        *itemNameLbl_;
    Wt::WLineEdit    *itemNameInput_;
    Wt::WText        *itemMeasTypeLbl_;
    Wt::WLineEdit    *itemMeasTypeInput_;
    Wt::WText        *itemQtyLbl_;
    Wt::WLineEdit    *itemQtyInput_;
    Wt::WText        *itemDatePurchLbl_;
    Wt::WLineEdit    *itemDatePurchInput_;
    Wt::WText        *itemExpDateLbl_;
    Wt::WLineEdit    *itemExpDateInput_;
    Wt::WText        *itemDateThrLbl_;
    Wt::WLineEdit    *itemDateThrInput_;
    Wt::WPushButton  *addToStockBtn;
    Wt::WNavigationBar *navigation;

    Wt::Signal<int>   stockUpdated_;


public:

    WebView(const Model &model);
    ~WebView();
    void setModel(const Model &model);
    void display();
    WebView(const Wt::WEnvironment &env): Wt::WApplication(env);
    Wt::WContainerWidget* content();
    void onInternalPathChange();
    void header();
    void sidebar();
    void footer();
    void home();
    void page1();
    void checkInputs(std::string name, std::string meas_type, std::string qty, std::string date_purch, std::string exp, std::string threshold);
    void newItem();
    Wt::Signal<int>& stockUpdated() { return stockUpdated_; }
};
#endif

