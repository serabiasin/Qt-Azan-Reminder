#include "setting_azan/setting_kota.h"

setting_kota::setting_kota(QWidget *parent) : QWidget(parent)
{
testing=new QLabel("Setting");
QVBoxLayout *layout=new QVBoxLayout;
layout->addWidget(testing);

setLayout(layout);
}
