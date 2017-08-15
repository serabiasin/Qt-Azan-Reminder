#include "jadwal_azan.h"



jadwal_azan::jadwal_azan(QWidget *parent) : QWidget(parent)
{
    view_sholat=new QVBoxLayout;
    view_waktu=new QVBoxLayout;
    rapi=new QGridLayout;

//    this->set_azan_time(); soon
    this->set_variable();
    this->setting_up();
}

inline void jadwal_azan::set_variable(){
    shubuh_time=new QLabel("Subuh");
    dzuhur_time=new QLabel("Dzuhur");
    ashar_time=new QLabel("Ashar");
    maghrib_time=new QLabel("Maghrib");
    isha_time=new QLabel("Isya");

    shubuh_time->setStyleSheet( "color : Black" );
    dzuhur_time->setStyleSheet( "color : Black" );
    ashar_time->setStyleSheet( "color : Black" );
    maghrib_time->setStyleSheet( "color : Black" );
    isha_time->setStyleSheet( "color : Black" );
}

void jadwal_azan::setting_up(){

    view_sholat->addWidget(shubuh_time);
    view_sholat->addWidget(dzuhur_time);
    view_sholat->addWidget(ashar_time);
    view_sholat->addWidget(maghrib_time);
    view_sholat->addWidget(isha_time);

    rapi->addLayout(view_sholat,0,0);
    setLayout(rapi);
}
