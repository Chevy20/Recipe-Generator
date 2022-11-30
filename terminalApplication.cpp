/**
 * @file terminalApplication.cpp
 * @author Matthew Cheverie
 * @brief terminalApplication program. This program will be the launcher for the terminal app. It will create a terminal view and displayu it. 
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TerminalView.h"
using namespace std;
/**
 * @brief The main entry point for the terminal application
 * @param argc the argument counter
 * @param argv the command line arguments;
 * @author Matthew Cheverie
 * 
*/
int main(int argc, char** argv){
    Model* theModel = new Model();
    TerminalView* terminalApp = new TerminalView(theModel);
    terminalApp->display(); 
    exit(0);
}