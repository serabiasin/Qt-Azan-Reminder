#include "setting_azan/setting_kota.h"

#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QDir>//untuk mengecek eksistensi file database


/*Static Member must be initialized first*/
double setting_kota::latitude=0;
double setting_kota::longitude=0;
float setting_kota::zone_waktu=0;


/*Initialization Class*/
void setting_kota::setup_var(){

    nama_kota=new QComboBox;
    nama_negara=new QComboBox;
    timezone=new QComboBox;
    kota=new QLabel("Kota  ");
    country=new QLabel("Negara ");
    longitude_label=new QLabel("Longitude");
    latitude_label=new QLabel("Latitude");
    timezone_label=new QLabel("Timezone ");
    longitude_edit=new QLineEdit;
    longitude_edit->setReadOnly(true);
    latitude_edit=new QLineEdit;
    latitude_edit->setReadOnly(true);
    oke=new QPushButton("Oke");


    country->setStyleSheet("color : Black");
    kota->setStyleSheet("color : Black");
    longitude_label->setStyleSheet("color : Black");
    latitude_label->setStyleSheet("color : Black");
    longitude_edit->setStyleSheet("color : Black");
    latitude_edit->setStyleSheet("color : Black");
    nama_kota->setStyleSheet("color : Black");
    timezone->setStyleSheet("color : Black");
    nama_negara->setStyleSheet("color : Black");
    oke->setStyleSheet("color : Black");
    timezone_label->setStyleSheet("color : Black");

}

setting_kota::setting_kota(jadwal_azan *sandilewat,QWidget *parent) : QWidget(parent)
{
    remote=sandilewat; //memberi address pertama (pointer to pointer jadinya)
    this->setup_var();
    this->setting_group();

}

void setting_kota::insert_group(){

    QString perintah="SELECT *FROM database_kota WHERE iso3='IDN' ORDER BY iso3 ASC";
    QSqlQuery query;
    query.exec(perintah);
    int baris=0;
    int init_tz=7;

    for(int x=0;x<3;x++){
        timezone->insertItem(x,QString::number(init_tz++));
    }

    while (query.next()) {
        QString city;
        city=query.value(0).toString();
        nama_kota->insertItem(baris++,city);

        if(baris==1){
            QString country_box;
            country_box=query.value(5).toString();
            nama_negara->insertItem(0,country_box);
        }

    }
}

void setting_kota::setup_database(){

    /*Debugging purpose*/
//    qDebug()<<QFile::exists("database_city.db");
//    qDebug()<<QDir::currentPath();

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database_city.db");

    if(!db.open()){
        QMessageBox::critical(this,"Mabok",tr("Error : ")+db.lastError().text());
       return;
    }


}

void setting_kota::setting_group(){

    this->setup_database();
    this->insert_group();

    layout=new QVBoxLayout;
    QVBoxLayout *layout_combo=new QVBoxLayout;
    QGridLayout *rapi=new QGridLayout;

    layout->addWidget(country);
    layout->addWidget(kota);
    layout->addWidget(longitude_label);
    layout->addWidget(latitude_label);
    layout->addWidget(timezone_label);

    layout_combo->addWidget(nama_negara);
    layout_combo->addWidget(nama_kota);
    layout_combo->addWidget(longitude_edit);
    layout_combo->addWidget(latitude_edit);
    layout_combo->addWidget(timezone);

    rapi->addLayout(layout,0,0);
    rapi->addLayout(layout_combo,0,1);
    rapi->addWidget(oke,1,1);

    setLayout(rapi);


    QObject::connect(oke,SIGNAL(clicked()),this,SLOT(oke_clicked()));
}

void setting_kota::set_timezone(float timezone_string){
    zone_waktu = timezone_string;
}

  void setting_kota::set_longitude(double _longitude){
    longitude=_longitude;

}

void setting_kota::set_latitude(double _latitude){

    latitude=_latitude;

}




double setting_kota::get_latitude(){
    return latitude;
}

double setting_kota::get_longitude(){
    return longitude;
}

float setting_kota::get_timezone(){
    return zone_waktu;

}

void setting_kota::oke_clicked(){

    QSqlQuery query_fetch; //to fetch latitude and longitude

   /*Open Query again in here*/
    query_fetch.prepare("SELECT *FROM database_kota WHERE city= ? ");
    query_fetch.addBindValue(nama_kota->currentText());
    query_fetch.exec();
    query_fetch.next();

    /*insert into QLineEdit*/
    longitude_edit->clear();
    latitude_edit->clear();

    longitude_edit->insert(query_fetch.value(3).toString());
    latitude_edit->insert(query_fetch.value(2).toString());

    /*assign the longitude and latitude to static procedure*/
    set_latitude(query_fetch.value(2).toDouble());
    set_longitude(query_fetch.value(3).toDouble());
    set_timezone(timezone->currentText().toDouble());


    this->calculate_time();
}

void setting_kota::calculate_time(){
    azan_calc object(setting_kota::get_longitude(),setting_kota::get_latitude(),setting_kota::get_timezone());
    /*cara agar mengupdate widget jadwal azan tanpa di refresh
    combo -> pass pointer dan definisi friend class di class jadwal
    */
    remote->set_time_table();


}

