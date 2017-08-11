#include "about/about_us.h"

about_us::about_us(QWidget *parent) : QWidget(parent)
{
test=new QLabel("About Us");
QVBoxLayout *layout=new QVBoxLayout;
layout->addWidget(test);
setLayout(layout);

}
