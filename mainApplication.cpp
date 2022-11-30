#include "TerminalView.h"
#include "WebView.h"
#include <fstream>
using namespace Wt;
static int launch(int argc, char**argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
      return std::make_unique<WebView>(env);
    });    
}
int main(int argc, char** argv){
    launch(argc,argv);
    Model* theModel = new Model();
    const WEnvironment& env = WApplication::instance()->environment();
    WebView* webApp = new WebView(env);
    webApp->setModel(theModel);
    std::fstream fs; 
    fs.open("http://0.0.0.0:9080");
    fs.close();
    TerminalView* terminalApp = new TerminalView(theModel);
    terminalApp->display();
    
}