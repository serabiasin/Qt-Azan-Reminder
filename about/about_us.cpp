#include "about/about_us.h"

about_us::about_us(QWidget *parent) : QWidget(parent)
{

layout=new QGridLayout;
html_embeded=new QLabel;
this->set_about();

}

void about_us::set_about(){
    html_embeded->setText("<p style=""text-align: center;""><span style=""color: #800000;"">About Us</span></p>\
    <p style=""text-align: left;""><span style=""color: #800000;"">This software is just for fun and make the user especially for moslem to remind the time to shalat when its comes.</span></p>\
    <p style=""text-align: left;"">&nbsp;</p>\
    <p style=""text-align: left;""><span style=""color: #800000;"">Credited to :</span></p>\
    <p style=""text-align: left;"">&nbsp;</p>\
    <div>Icons made by:</div>\
    <div>-<a title=""Madebyoliver"" href=""https://www.flaticon.com/authors/madebyoliver"">Madebyoliver</a> from <a>www.flaticon.com</a></div>\
    <div>-<a href=""https://www.flaticon.com/authors/google"" target="_blank">google</a> from www.flaticon.com</div>\
    <div>-<a href=""https://www.flaticon.com/authors/business-dubai" "target="_blank">business-dubai</a> from www.flaticon.com</div>\
    <div>is licensed by <a title=""Creative Commons BY 3.0"" href=""http://creativecommons.org/licenses/by/3.0/" "target="_blank">CC 3.0 BY</a></div>\
    <div>&nbsp;</div>\
    <div>And algorithm from :</div>\"");
    layout->addWidget(html_embeded,0,0);

    setLayout(layout);


}
