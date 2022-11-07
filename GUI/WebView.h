/*
 * View.h
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

#include<Model.h>
#include<View.h>


class WebView: public View {
    
    private:
        Model model;
    
    public:
        WebView(const Model &model);
        ~WebView();
        void setModel(Model &model);
        void display();
};
#endif

