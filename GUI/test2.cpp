
#include "test.hpp"
#include "Wt/WPanel.h"
#include "Wt/WLink.h"
#include "Wt/WPopupMenu.h"
#include "Wt/WMessageBox.h"
#include <memory>
#include <Wt/WHBoxLayout.h>
#include <iostream>

using namespace Wt;

WebView::WebView(const WEnvironment& env) : WApplication(env){

    appName_ = "Freshcipes WebView";
    setTitle(appName_);
    content_ = 0;
    // internalPathChanged().connect(this, &WebView::onInternalPathChange);
    
    // Sets the web theme to Bootstrap 5
    this->setTheme(std::make_shared<WBootstrap5Theme>());


    auto container = std::make_unique<Wt::WContainerWidget>();

    Wt::WPushButton *button = container->addNew<Wt::WPushButton>("Status");

    Wt::WText *out = container->addNew<Wt::WText>();
    out->setMargin(10, Wt::Side::Left);

    auto c = container.get();
    button->clicked().connect([=] {
        out->setText("The status button is clicked.");

        auto messageBox =
        c->addChild(std::make_unique<Wt::WMessageBox>(
                    "Status",
                    "<p>Ready to launch the rocket...</p>"
                    "<p>Launch the rocket immediately?</p>",
                    Wt::Icon::Information,
                    Wt::StandardButton::Yes | Wt::StandardButton::No));

        messageBox->setModal(false);

        messageBox->buttonClicked().connect([=] {
            if (messageBox->buttonResult() == Wt::StandardButton::Yes)
                out->setText("The rocket is launched!");
            else
                out->setText("The rocket is ready for launch...");

            c->removeChild(messageBox);
        });

        messageBox->show();
    });
}
/**
 * Launch the app
*/
int WebView::launch(int argc, char** argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return std::make_unique<WebView>(env);
    });
}

int main(int argc, char** argv){
    WebView::launch(argc, argv);
}
