#include "jadwal_azan.h"
#include "QDebug"


jadwal_azan::jadwal_azan(QWidget *parent) : QWidget(parent)
{
    view_sholat=new QVBoxLayout;
    view_waktu=new QVBoxLayout;
    rapi=new QGridLayout;
    view_estimated=new QHBoxLayout;

//    this->set_azan_time(); soon
    this->set_variable();
    this->setting_up();
}

 void jadwal_azan::set_variable(){
    shubuh_time=new QLabel("Subuh");
    dzuhur_time=new QLabel("Dzuhur");
    ashar_time=new QLabel("Ashar");
    maghrib_time=new QLabel("Maghrib");
    isha_time=new QLabel("Isya");
    estimated=new QLabel("Waktu Sholat Terdekat Tinggal : ");
    time_estimated=new QLabel("%d");

    time_estimated->setStyleSheet( "color : Black" );
    shubuh_time->setStyleSheet( "color : Black" );
    dzuhur_time->setStyleSheet( "color : Black" );
    ashar_time->setStyleSheet( "color : Black" );
    maghrib_time->setStyleSheet( "color : Black" );
    isha_time->setStyleSheet( "color : Black" );
    estimated->setStyleSheet( "color : Black" );

    for(int count=0;count<5;count++ ){
        time[count]=new QLabel("%s");
        time[count]->setStyleSheet("color : Black");
    }


}

void jadwal_azan::setting_up(){

    view_estimated->addWidget(estimated);
    view_estimated->addWidget(time_estimated);

    view_sholat->addWidget(shubuh_time);
    view_sholat->addWidget(dzuhur_time);
    view_sholat->addWidget(ashar_time);
    view_sholat->addWidget(maghrib_time);
    view_sholat->addWidget(isha_time);

    for(int count=0;count<5;count++ ){
    view_waktu->addWidget(time[count]);
    }


    rapi->addLayout(view_sholat,0,0);
    rapi->addLayout(view_waktu,0,1);
    rapi->addLayout(view_estimated,1,0);

    setLayout(rapi);
}
