#include "jadwal_azan.h"

jadwal_azan::jadwal_azan(QWidget *parent) : QWidget(parent)
{
QLabel *testing=new QLabel("Jadwal Azan");
layout=new QVBoxLayout;
layout->addWidget(testing);
setLayout(layout);
}
