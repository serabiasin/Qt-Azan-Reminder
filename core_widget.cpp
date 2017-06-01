#include "core_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTabWidget *tab_tools=new QTabWidget();
    setting_kota *sett=new setting_kota(NULL);
    tab_tools->addTab(sett,"Setting Kota");
    tab_tools->setParent(this);
    this->show();
}

Widget::~Widget()
{

}
