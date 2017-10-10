#include "jadwal_azan.h"
#include "QDebug"
#include <iomanip>


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
    time_estimated=new QLabel("%d");

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

        QString jam=QString::number(temp1);
        QString menit=QString::number(temp2);

        switch (count) {
            /*subuh*/
            case 0:
                {
                temp_mentah=azan_calc::get_subuh();
                convert_to_hour(temp_mentah,temp1,temp2);
                jam=QString::number(temp1);
                menit=QString::number(temp2);
                /*Add logic here to make 9 to 09*/
                if(temp2<10){
                    time_azan[count]->setText("0"+jam +":0"+menit);
                }
                else
                    { time_azan[count]->setText(jam +":"+menit);
                }

                break;
                }
            /*Dzuhur*/
        case 1:{
            temp_mentah=azan_calc::get_dzuhur();
            convert_to_hour(temp_mentah,temp1,temp2);
            jam=QString::number(temp1);
            menit=QString::number(temp2);
            if(temp2<10){
                  time_azan[count]->setText("0"+jam +":0"+menit);
            }
            else
                { time_azan[count]->setText(jam +":"+menit);
            }



            break;
            }
            /*Ashar*/
        case 2:{
            temp_mentah=azan_calc::get_ashar();
            convert_to_hour(temp_mentah,temp1,temp2);
            jam=QString::number(temp1);
            menit=QString::number(temp2);
            if(temp2<10){
                  time_azan[count]->setText("0"+jam +":0"+menit);}
            else
                { time_azan[count]->setText(jam +":"+menit);
            }

                break;
            }

            /*Magrib*/
            case 3:
            {
            temp_mentah=azan_calc::get_magrib();
            convert_to_hour(temp_mentah,temp1,temp2);
            jam=QString::number(temp1);
            menit=QString::number(temp2);
            if(temp2<10){
                time_azan[count]->setText("0"+jam +":0"+menit);
            }
            else
                { time_azan[count]->setText(jam +":"+menit);
            }

                break;
            }
            /*Isya*/
            case 4:
        {
            temp_mentah=azan_calc::get_isya();
            convert_to_hour(temp_mentah,temp1,temp2);
            jam=QString::number(temp1);
            menit=QString::number(temp2);
            if(temp2<10){
                  time_azan[count]->setText("0"+jam +":0"+menit);
            }
            else
                { time_azan[count]->setText(jam +":"+menit);
            }

            break;
        }

            }

    }
}


