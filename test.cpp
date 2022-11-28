#include "test.h"

using namespace Wt;

WebViewTest::WebViewTest(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    // Define model
    model = new Model();

    setTitle("Freshcipes");
    setTheme(std::make_shared<WBootstrap5Theme>());

    // auto addStockCont = addStockItem();
    // root()->addWidget(std::unique_ptr<WContainerWidget>(addStockCont));

    auto deleteStockCont = deleteStockItem();
    root()->addWidget(std::unique_ptr<WContainerWidget>(deleteStockCont));

}

// Add Stock Item
WContainerWidget* WebViewTest::addStockItem(){

    auto addStockCont = new WContainerWidget();

    // Item Name
    auto nameContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());
    nameContainer->setId("nameContainer");
    // nameContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Mesurement Unit Entry
    auto unitContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    unitContainer->addWidget(std::make_unique<Wt::WText>("Measurement Unit"));
    unitEdit_ = unitContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    unitContainer->addWidget(std::make_unique<Wt::WBreak>());
    unitContainer->setId("unitContainer");
    // unitContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Quantity Entry
    auto qtyContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    qtyContainer->addWidget(std::make_unique<Wt::WText>("Quantity"));
    qtyEdit_ = qtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    qtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    qtyContainer->setId("qtyContainer");
    // qtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Date Purchased Entry
    auto purchaseContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    purchaseContainer->addWidget(std::make_unique<Wt::WText>("Purchase Date (YYYY/MM/DD)"));
    purchaseEdit_ = purchaseContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    purchaseContainer->addWidget(std::make_unique<Wt::WBreak>());
    purchaseContainer->setId("purchaseContainer");
    // purchaseContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Expiry Date Entry
    auto expiryContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    expiryContainer->addWidget(std::make_unique<Wt::WText>("Expiration Date (YYYY/MM/DD)"));
    expiryEdit_ = expiryContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    expiryContainer->addWidget(std::make_unique<Wt::WBreak>());
    expiryContainer->setId("expiryContainer");
    // expiryContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Storage Location Entry
    auto locationContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    locationContainer->addWidget(std::make_unique<Wt::WText>("Storage Location"));
    locationEdit_ = locationContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    locationContainer->addWidget(std::make_unique<Wt::WBreak>());
    locationContainer->setId("locationContainer");
    // locationContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Stock Low Alert Quantity Entry
    auto alertQtyContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WText>("Low Qty Threshold"));
    alertQtyEdit_ = alertQtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    alertQtyContainer->setId("locationContainer");
    // alertQtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Add to Stock Pushbutton
    Wt::WPushButton *addItemBtn = addStockCont->addWidget(std::make_unique<Wt::WPushButton>("Add Item to Stock"));
    addStockCont->addWidget(std::make_unique<Wt::WBreak>());
    addStockCont->addWidget(std::make_unique<Wt::WBreak>());
    
    // Build the FoodItem and connect the Add stock button
    auto addItem = [this]{
      FoodItem *fi = new FoodItem(nameEdit_->text().toUTF8(), std::stoi(qtyEdit_->text().toUTF8()), 
        unitEdit_->text().toUTF8(), purchaseEdit_->text().toUTF8(), 
        expiryEdit_->text().toUTF8(), locationEdit_->text().toUTF8(), std::stoi(alertQtyEdit_->text().toUTF8()));
      model->addFoodItem(*fi);
      std::cerr<<"\nMADE IT HERE\n";
    };
    addItemBtn->clicked().connect(addItem);

    addStockCont->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));
    return addStockCont;
}

// Delete Stock Item
WContainerWidget* WebViewTest::deleteStockItem(){

    auto deleteStockCont = new WContainerWidget();

    // Item Name
    auto nameContainer = deleteStockCont->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());
    nameContainer->setId("nameContainer");

    // Delete Stock Pushbutton
    Wt::WPushButton *deleteItemBtn = deleteStockCont->addWidget(std::make_unique<Wt::WPushButton>("Delete Item"));
    deleteStockCont->addWidget(std::make_unique<Wt::WBreak>());
    deleteStockCont->addWidget(std::make_unique<Wt::WBreak>());
    
    // Delete the item from the model
    auto deleteItem = [this]{
      model->removeFoodItem(nameEdit_->text().toUTF8());
      std::cout << nameEdit_->text() << " successfully deleted!" << std::endl;
    };
    deleteItemBtn->clicked().connect(deleteItem);

    deleteStockCont->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));
    return deleteStockCont;
}

// Launch Application
static int launch(int argc, char**argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
      return std::make_unique<WebViewTest>(env);
    });    
}

int main(int argc, char **argv)
{
    launch(argc, argv);
}

