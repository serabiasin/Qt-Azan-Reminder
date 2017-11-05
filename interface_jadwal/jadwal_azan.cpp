#include "jadwal_azan.h"
#include "QDebug"


jadwal_azan::jadwal_azan(QWidget *parent) : QWidget(parent)
{
    view_sholat=new QVBoxLayout;
    view_waktu=new QVBoxLayout;
    rapi=new QGridLayout;
    view_estimated=new QHBoxLayout;

    this->set_variable();
    this->setting_up();
    this->set_time_table();


}

 void jadwal_azan::set_variable(){

    shubuh_time=new QLabel("Subuh");
    dzuhur_time=new QLabel("Dzuhur");
    ashar_time=new QLabel("Ashar");
    maghrib_time=new QLabel("Maghrib");
    isha_time=new QLabel("Isya");
    estimated=new QLabel("Waktu Sholat Terdekat Tinggal : ");
    /*Will combine with QTime*/
    time_estimated=new QLabel;
    timer=new QTimer(this);

    time_estimated->setStyleSheet( "color : Black" );
    shubuh_time->setStyleSheet( "color : Black" );
    dzuhur_time->setStyleSheet( "color : Black" );
    ashar_time->setStyleSheet( "color : Black" );
    maghrib_time->setStyleSheet( "color : Black" );
    isha_time->setStyleSheet( "color : Black" );
    estimated->setStyleSheet( "color : Black" );
    for(int count=0;count<5;count++ ){

        time_azan[count]=new QLabel;
        time_azan[count]->setStyleSheet("color : Black");

    }

    //testing function
//    QTime object(QTime::currentTime()); //setting up local time
    connect(timer,SIGNAL(timeout()),this,SLOT(update_time()));
    timer->start(30000);

    /* Coming soon : real time count down sholat

    qDebug()<<object.minute(); //get current minute
    qDebug()<<object.hour(); //get current hour

*/

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
    view_waktu->addWidget(time_azan[count]);
    }


    rapi->addLayout(view_sholat,0,0);
    rapi->addLayout(view_waktu,0,1);
    rapi->addLayout(view_estimated,1,0);

    setLayout(rapi);
}



 void jadwal_azan::set_time_table(){
        int temp1=0,temp2=0; //temp 1= jam,temp 2=menit
        double temp_mentah;



    for(int count=0;count<5;count++ ){

      /*  QString jam=QString::number(temp1);
        QString menit=QString::number(temp2);
*/
        switch (count) {
            /*subuh*/
            case 0:
                {

                temp_mentah=azan_calc::get_subuh();
                convert_to_hour(temp_mentah,temp1,temp2);
                QTime converter(temp1,temp2);
                time_azan[count]->setText(converter.toString("hh:mm"));
                break;
                }
            /*Dzuhur*/
        case 1:{
            temp_mentah=azan_calc::get_dzuhur();
            convert_to_hour(temp_mentah,temp1,temp2);
            QTime converter(temp1,temp2);
            time_azan[count]->setText(converter.toString("hh:mm"));



            break;
            }
            /*Ashar*/
        case 2:{
            temp_mentah=azan_calc::get_ashar();
            convert_to_hour(temp_mentah,temp1,temp2);
            QTime converter(temp1,temp2);
            time_azan[count]->setText(converter.toString("hh:mm"));
                break;
            }

            /*Magrib*/
            case 3:
            {
            temp_mentah=azan_calc::get_magrib();
            convert_to_hour(temp_mentah,temp1,temp2);
            QTime converter(temp1,temp2);
            time_azan[count]->setText(converter.toString("hh:mm"));
                break;
            }
            /*Isya*/
            case 4:
        {
            temp_mentah=azan_calc::get_isya();
            convert_to_hour(temp_mentah,temp1,temp2);
            QTime converter(temp1,temp2);
            time_azan[count]->setText(converter.toString("hh:mm"));

            break;
        }

            }

    }
}


 void jadwal_azan::update_time(){
    QTime tumbal(tumbal.currentTime());
    time_estimated->setText(tumbal.toString("hh:mm"));

 }
