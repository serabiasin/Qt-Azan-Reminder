#include "core_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Azan Reminder");
    this->resize(390,600);
    this->setStyleSheet("background-color:#006600");
    layout_stacked=new QHBoxLayout;
    layout_tombol=new QVBoxLayout;
    buat_rapi=new QGridLayout;
    sett_frame1=new QFrame;
    sett_frame2=new QFrame;
    tombol_group=new QBoxLayout(QBoxLayout::TopToBottom,NULL);

    core_view=new QStackedLayout;
    sett_ui=new setting_kota(NULL);
    jadwal=new jadwal_azan(NULL);
    about_kita=new about_us(NULL);
    tombol[0]=new QPushButton; //Setting
    tombol[0]->setIcon(QIcon(":/icon_dir/controls.svg"));

    tombol[1]=new QPushButton; //about
    tombol[1]->setIcon(QIcon(":/icon_dir/info.svg"));

    tombol[2]=new QPushButton; //schedule
    tombol[2]->setIcon(QIcon(":/icon_dir/schedule-button.svg"));
    for(int x=0;x<3;x++){
        tombol[x]->setFixedSize(50,50);
        tombol[x]->setFlat(true);
    }

    /*Setting up layout sisi kiri*/

    tombol_group->addWidget(tombol[2]);
    tombol_group->addWidget(tombol[0]);
    tombol_group->addWidget(tombol[1]);
    layout_tombol->addLayout(tombol_group);

    sett_frame2->setLayout(layout_tombol);
    sett_frame2->setFrameShape(QFrame::NoFrame);
    sett_frame2->setStyleSheet("background-color:#006600");

    /*Setting up layout stack view*/
    layout_stacked->addLayout(core_view);
    sett_frame1->setLayout(layout_stacked);
    sett_frame1->setFrameShadow(QFrame::Sunken);
    sett_frame1->setFrameShape(QFrame::Box);
    sett_frame1->setLineWidth(2);
    sett_frame1->setMidLineWidth(0);
    sett_frame1->setStyleSheet("background-color:White");


    /*Place here if u want add widget*/
    core_view->addWidget(sett_ui);
    core_view->addWidget(about_kita);
    core_view->addWidget(jadwal);
    core_view->currentIndex();



    /*qDebug()<<core_view->currentIndex();*/ //dimulai dari 0 index sebuah widget
    buat_rapi->addWidget(sett_frame2,0,0);
    buat_rapi->addWidget(sett_frame1,0,1);

    connect(tombol[0],SIGNAL(clicked()),this,SLOT(change_to_setting()));
    connect(tombol[1],SIGNAL(clicked()),this,SLOT(change_to_about()));
    connect(tombol[2],SIGNAL(clicked()),this,SLOT(change_to_jadwal()));


    setLayout(buat_rapi);
}

Widget::~Widget()
{

    delete core_view;
    delete sett_ui;
    delete about_kita;
    delete layout_stacked;
    delete layout_tombol;

}

void Widget::change_to_setting(){
    core_view->setCurrentIndex(0);

}


void Widget::change_to_jadwal(){
    core_view->setCurrentIndex(2);


}
void Widget::change_to_about(){
    core_view->setCurrentIndex(1);

}
