#include "setting_kota.h"

setting_kota::setting_kota(QWidget *parent) : QWidget(parent)
{
testing=new QLabel("Test");
QVBoxLayout *layout=new QVBoxLayout;
layout->addWidget(testing);

setLayout(layout);
}
