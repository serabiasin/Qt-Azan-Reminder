#include "about/about_us.h"

about_us::about_us(QWidget *parent) : QWidget(parent)
{

layout=new QGridLayout;

this->set_about();

}

void about_us::set_about(){
    QWebView *show_it=new QWebView();
    show_it->load(QUrl("qrc:/res_about/about.html"));
    layout->addWidget(show_it,0,0);
    setLayout(layout);
}
