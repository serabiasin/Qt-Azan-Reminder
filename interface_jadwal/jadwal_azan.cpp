#include "jadwal_azan.h"

jadwal_azan::jadwal_azan(QWidget *parent) : QWidget(parent)
{

    layout_rapi=new QGroupBox(tr("Jadwal Azan Hari ini :"));
    view=new QVBoxLayout;


    this->setting_up();
}


void jadwal_azan::setting_up(){

QTableWidget *tabel=new QTableWidget;
tabel->setColumnCount(2);
tabel->setRowCount(4);

QStringList header;
header<<"Sholat"<<"Waktu";
tabel->setHorizontalHeaderLabels(header);
//tabel->setItem(0,0,QTableWidgetItem("Subuh"));

view->addWidget(tabel);
setLayout(view);




}
