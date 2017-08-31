#include "setting_azan/setting_kota.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

void setting_kota::setup_var(){
    nama_kota=new QComboBox;
    nama_negara=new QComboBox;
    kota=new QLabel("Kota  ");
    country=new QLabel("Negara ");
    longitude_label=new QLabel("Longitude");
    latitude_label=new QLabel("Latitude");
    longitude_edit=new QLineEdit;
    latitude_edit=new QLineEdit;
    oke=new QPushButton("Oke");


    country->setStyleSheet("color : Black");
    kota->setStyleSheet("color : Black");
    longitude_label->setStyleSheet("color : Black");
    latitude_label->setStyleSheet("color : Black");
    longitude_edit->setStyleSheet("color : Black");
    latitude_edit->setStyleSheet("color : Black");
    nama_kota->setStyleSheet("color : Black");
    nama_negara->setStyleSheet("color : Black");
    oke->setStyleSheet("color : Black");
}

setting_kota::setting_kota(QWidget *parent) : QWidget(parent)
{
    this->setup_var();
    this->setting_group();

}

void setting_kota::setup_database(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","Connection");
    db.setDatabaseName("database_city.sqlite");
    if(!db.open()){
        QMessageBox::critical(this,"Mabok",tr("Error : ")+db.lastError().text());
       return;
    }


}

void setting_kota::setting_group(){
    this->setup_database();
    layout=new QVBoxLayout;
    QVBoxLayout *layout_combo=new QVBoxLayout;
    QGridLayout *rapi=new QGridLayout;

    layout->addWidget(country);
    layout->addWidget(kota);
    layout->addWidget(longitude_label);
    layout->addWidget(latitude_label);

    layout_combo->addWidget(nama_negara);
    layout_combo->addWidget(nama_kota);
    layout_combo->addWidget(longitude_edit);
    layout_combo->addWidget(latitude_edit);

    rapi->addLayout(layout,0,0);
    rapi->addLayout(layout_combo,0,1);
    rapi->addWidget(oke,1,1);


    setLayout(rapi);
}
