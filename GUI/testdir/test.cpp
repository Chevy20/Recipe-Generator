#include "test.h"

using namespace Wt;

WebViewTest::WebViewTest(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    // Define model
    Model *model = new Model();

    setTitle("Freshcipes");
    setTheme(std::make_shared<WBootstrap5Theme>());

    // Item Name
    auto nameContainer = root()->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());

    // Mesurement Unit Entry
    root()->addWidget(std::make_unique<Wt::WText>("Measurement Unit"));
    unitEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    // Quantity Entry
    root()->addWidget(std::make_unique<Wt::WText>("Quantity"));
    qtyEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    // Date Purchased Entry
    root()->addWidget(std::make_unique<Wt::WText>("Purchase Date (YYYY/MM/DD)"));
    purchaseEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    // Expiry Date Entry
    root()->addWidget(std::make_unique<Wt::WText>("Expiration Date (YYYY/MM/DD)"));
    expiryEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    // Storage Location Entry
    root()->addWidget(std::make_unique<Wt::WText>("Storage Location"));
    expiryEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    // Stock Low Alert Quantity Entry
    root()->addWidget(std::make_unique<Wt::WText>("Low Qty Threshold"));
    expiryEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    // Add to Stock Pushbutton
    Wt::WPushButton *addItemBtn = root()->addWidget(std::make_unique<Wt::WPushButton>("Add Item to Stock"));
    root()->addWidget(std::make_unique<Wt::WBreak>());
    root()->addWidget(std::make_unique<Wt::WBreak>());
    greeting_ = root()->addWidget(std::make_unique<Wt::WText>());
    auto addItem = [this]{
      greeting_->setText("Hello there, " + nameEdit_->text());
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

