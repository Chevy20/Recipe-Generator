/*
 * View.h
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

#include<View.h>
#include <Wt/WContainerWidget.h>
#include <Wt/Signals>
#include <Wt/WLineEdit.h>

class WebView : public Wt::WContainerWidget
{
public:
    WebView(const std::string &name);

    Wt::Signal<int>& stockUpdated() { return stockUpdated_; }

private:
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

    Wt::Signal<int>   stockUpdated_;


    void checkInputs(string name, string meas_type, string qty, string date_purch, string exp, string threshold);
    void newItem();
};
#endif

