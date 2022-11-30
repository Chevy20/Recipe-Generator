/*
 * WebView.h
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

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

#include "View.h"
#include "Model.h"
#include "FoodItem.h"

// CONSTANTS
#define APP_NAME "Freshcipes"
#define INPUT_WIDTH_PERCENT 80
#define NAV_BUTTON_WIDTH 80

static int launch(int argc, char **argv);

class WebView : public Wt::WApplication, public View
{
public:
    WebView(const Wt::WEnvironment& env);
    virtual ~WebView() = default;
    Wt::WApplication *app;

    // Inherited functions
    virtual Model* getModel();
    virtual void setModel(Model *model);
    virtual void display();

private:

    // Path constants for nav buttons
    const std::string addItemPath = "/?_=add-to-stock";
    const std::string deleteItemPath = "/?_=delete-from-stock";
    const std::string modItemPath = "/?_=modify-stock";
    const std::string findItemPath = "/?_=find-stock";
    const std::string getAllStockPath = "/?_=get-all-stock";
    const std::string findRecipeByItemPath = "/?_=find-recipe-by-items";
    const std::string findRecipeAllStockPath = "/?_=find-recipe-for-all-stock";

    // Model
    Model *model;

    // Layout and containers for content
    Wt::WHBoxLayout *horizBox;
    Wt::WContainerWidget *leftContent_;
    Wt::WContainerWidget *rightContent_;    

    // Add Stock Item
    Wt::WLineEdit *nameEdit_;
    Wt::WLineEdit *unitEdit_;
    Wt::WLineEdit *qtyEdit_;
    Wt::WLineEdit *purchaseEdit_;
    Wt::WLineEdit *expiryEdit_;
    Wt::WLineEdit *locationEdit_;
    Wt::WLineEdit *alertQtyEdit_;
    Wt::WContainerWidget *internalStockCont_;  
    Wt::WContainerWidget *internalRecipeCont_;
    
    // Structural containers
    Wt::WContainerWidget* navbar();
    Wt::WContainerWidget* sidebar();
    Wt::WContainerWidget* inputContent();
    Wt::WContainerWidget* recipeContent();

    // Functional containers
    Wt::WContainerWidget* addStockItem();
    Wt::WContainerWidget* deleteStockItem();
    Wt::WContainerWidget* modifyStockItem();
    Wt::WContainerWidget* findStockItem();
    Wt::WContainerWidget* getAllStock();
    Wt::WContainerWidget* findRecipeByItem();
    Wt::WContainerWidget* findRecipeForStock();
    Wt::WContainerWidget* selectRecipe();  // Not implemented yet

    // Handle internal path changes
    void handleInternalPathChange();
    
};

#endif