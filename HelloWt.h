#ifndef HELLOWT_H
#define HELLOWT_H

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WLineEdit.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;

class HelloWt : public WApplication
{
    private:
        WLineEdit *nameEdit;
        WText *greeting;

        void Greet(void);

    public:
        HelloWt(const WEnvironment &env);
};

#endif