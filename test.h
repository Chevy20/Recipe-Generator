#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WBreak.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WMenu.h>
#include <Wt/WLink.h>
#include <Wt/WMessageBox.h>
#include <Wt/WPanel.h>
#include <Wt/WHBoxLayout.h>

#include "Model.h"
#include "FoodItem.h"

#define APP_NAME "Freshcipes"
#define INPUT_WIDTH_PERCENT 80
#define NAV_BUTTON_WIDTH 80

static int launch(int argc, char **argv);

class WebViewTest : public Wt::WApplication
{
public:
    WebViewTest(const Wt::WEnvironment& env);
    Wt::WApplication *app;

private:
    const std::string addItemPath = "/?_=add-to-stock";
    const std::string deleteItemPath = "/?_=delete-from-stock";
    const std::string modItemPath = "/?_=modify-stock";
    const std::string findItemPath = "/?_=find-stock";

    // Model
    Model *model;

    Wt::WHBoxLayout *horizBox;
    Wt::WContainerWidget *content_;    

    // Add Stock Item
    Wt::WLineEdit *nameEdit_;
    Wt::WLineEdit *unitEdit_;
    Wt::WLineEdit *qtyEdit_;
    Wt::WLineEdit *purchaseEdit_;
    Wt::WLineEdit *expiryEdit_;
    Wt::WLineEdit *locationEdit_;
    Wt::WLineEdit *alertQtyEdit_;    
    
    // Structural containers
    Wt::WContainerWidget* navbar();
    Wt::WContainerWidget* sidebar();
    Wt::WContainerWidget* content();

    // Functional containers
    Wt::WContainerWidget* addStockItem();
    Wt::WContainerWidget* deleteStockItem();
    Wt::WContainerWidget* modifyStockItem();


    void handleInternalPathChange();
    
};