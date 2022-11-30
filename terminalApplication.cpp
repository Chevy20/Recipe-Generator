/*
    TerminalApplication File
    This File will act as the launcher for the terminalView 
*/
#include "TerminalView.h"
using namespace std;
/**
 * @brief The main entry point for the terminal application
 * @param argc the argument counter
 * @param argv the command line arguments;
 * 
*/
int main(int argc, char** argv){
    Model* theModel = new Model();
    TerminalView* terminalApp = new TerminalView(theModel);
    terminalApp->display(); 
}