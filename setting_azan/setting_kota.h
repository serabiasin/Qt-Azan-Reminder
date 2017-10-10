#ifndef SETTING_KOTA_H
#define SETTING_KOTA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QtSql/QSqlDatabase>
#include <QLineEdit>
#include <QPushButton>

#include "calculation_azan/azan_calculation.h"
#include "interface_jadwal/jadwal_azan.h"

/*Forward Declaration*/

class jadwal_azan;

class setting_kota : public QWidget
{
    Q_OBJECT

public:
    setting_kota(jadwal_azan *sandilewat, QWidget *parent = nullptr);
    static double get_latitude();
    static double get_longitude();
    static float  get_timezone();

    static void set_latitude(double _latitude);
    static void set_longitude(double _longitude);
    static void set_timezone(float timezone_string);

    void setup_database();
    void setup_var();
    void setting_group();
    void insert_group();
    void calculate_time(); //this will initiate object from azan_calculation);

public slots:
    void oke_clicked();
private:
    //this for store the from database
    static double latitude;
    static double longitude;

    //for timezone
    static float zone_waktu;

    /*Supporting component*/
    QLabel *country;
    QLabel *kota;
    QLabel *longitude_label;
    QLabel *latitude_label;
    QLabel *timezone_label;

    QComboBox *nama_negara;
    QComboBox *nama_kota;
    QComboBox *timezone; //timezone indonesia : +7,+8,+9
    QVBoxLayout *layout;

    QLineEdit *longitude_edit;
    QLineEdit *latitude_edit;

    QPushButton *oke;

    jadwal_azan *remote;

};

#endif // SETTING_KOTA_H
