#include <HelloWt.h>

void HelloWt::Greet(void)
{
    greeting->setText("Hello there, " + nameEdit->text());
}

HelloWt::HelloWt(const WEnvironment &env) : WApplication(env)
{
    setTitle("Hello World");

    root()->addWidget(new WText("Your name, please? "));
}