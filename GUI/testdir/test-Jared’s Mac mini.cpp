#include "test.h"

using namespace Wt;

WebViewTest::WebViewTest(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    // Define model
    model = new Model();

    setTitle("Freshcipes");
    setTheme(std::make_shared<WBootstrap5Theme>());

    auto inputContainer = root()->addWidget(std::make_unique<WContainerWidget>());

    // Item Name
    auto nameContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());
    nameContainer->setId("nameContainer");
    nameContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Mesurement Unit Entry
    auto unitContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    unitContainer->addWidget(std::make_unique<Wt::WText>("Measurement Unit"));
    unitEdit_ = unitContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    unitContainer->addWidget(std::make_unique<Wt::WBreak>());
    unitContainer->setId("unitContainer");
    unitContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Quantity Entry
    auto qtyContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    qtyContainer->addWidget(std::make_unique<Wt::WText>("Quantity"));
    qtyEdit_ = qtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    qtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    qtyContainer->setId("qtyContainer");
    qtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Date Purchased Entry
    auto purchaseContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    purchaseContainer->addWidget(std::make_unique<Wt::WText>("Purchase Date (YYYY/MM/DD)"));
    purchaseEdit_ = purchaseContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    purchaseContainer->addWidget(std::make_unique<Wt::WBreak>());
    purchaseContainer->setId("purchaseContainer");
    purchaseContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Expiry Date Entry
    auto expiryContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    expiryContainer->addWidget(std::make_unique<Wt::WText>("Expiration Date (YYYY/MM/DD)"));
    expiryEdit_ = expiryContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    expiryContainer->addWidget(std::make_unique<Wt::WBreak>());
    expiryContainer->setId("expiryContainer");
    expiryContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Storage Location Entry
    auto locationContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    locationContainer->addWidget(std::make_unique<Wt::WText>("Storage Location"));
    locationEdit_ = locationContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    locationContainer->addWidget(std::make_unique<Wt::WBreak>());
    locationContainer->setId("locationContainer");
    locationContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Stock Low Alert Quantity Entry
    auto alertQtyContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WText>("Low Qty Threshold"));
    alertQtyEdit_ = alertQtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    alertQtyContainer->setId("locationContainer");
    alertQtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));


    // Add to Stock Pushbutton
    Wt::WPushButton *addItemBtn = root()->addWidget(std::make_unique<Wt::WPushButton>("Add Item to Stock"));
    root()->addWidget(std::make_unique<Wt::WBreak>());
    root()->addWidget(std::make_unique<Wt::WBreak>());
    
    auto addItem = [this]{
      FoodItem *fi = new FoodItem(nameEdit_->text().toUTF8(), std::stoi(qtyEdit_->text().toUTF8()), 
        unitEdit_->text().toUTF8(), purchaseEdit_->text().toUTF8(), 
        expiryEdit_->text().toUTF8(), locationEdit_->text().toUTF8(), std::stoi(alertQtyEdit_->text().toUTF8()));
    };
    addItemBtn->clicked().connect(addItem);
}

static int launch(int argc, char**argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
      return std::make_unique<WebViewTest>(env);
    });    
}

int main(int argc, char **argv)
{
    launch(argc, argv);
}

