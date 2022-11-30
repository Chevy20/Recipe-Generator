/**
 * @file webApplication.cpp
 * @author Matthew Cheverie
 * @author Jared Anstett
 * @brief webApplication runs an application that launches the Wt webserver and Wt web application and 
 * links it to the model
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "WebView.h"
#include <signal.h>
using namespace Wt;
using namespace std;

    /**
     * @brief this function will launch the wt Webserver and generate the URL for the web application
     * @param argc argument counter
     * @param argv command line arguments
     * @author Jared Anstett
    */
static int launch(int argc, char**argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
      return std::make_unique<WebView>(env);
    });    
}

    /**
     * @brief this function will launch the webserver and create the webView
     * @param argc argument counter
     * @param argv command line arguments
     * @author matthew Cheverie
    */
int main(int argc, char** argv){
  Model* theModel;
  WebView* webApp;
  launch(argc,argv);
  theModel = new Model();
  const WEnvironment& env = WApplication::instance()->environment();
  webApp = new WebView(env);
  webApp->setModel(theModel);
}