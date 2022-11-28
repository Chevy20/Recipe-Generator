#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WBootstrap5Theme.h>

#include "Model.h"
#include "FoodItem.h"

#define INPUT_WIDTH_PERCENT 35

static int launch(int argc, char **argv);

class WebViewTest : public Wt::WApplication
{
public:
    WebViewTest(const Wt::WEnvironment& env);

private:
    Model *model;

    // User entry
    Wt::WLineEdit *nameEdit_;
    Wt::WLineEdit *unitEdit_;
    Wt::WLineEdit *qtyEdit_;
    Wt::WLineEdit *purchaseEdit_;
    Wt::WLineEdit *expiryEdit_;
    Wt::WLineEdit *locationEdit_;
    Wt::WLineEdit *alertQtyEdit_;    

    Wt::WText *greeting_;
};