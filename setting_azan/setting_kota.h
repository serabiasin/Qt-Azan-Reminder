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

//#include "calculation_azan/azan_calculation.h"

class setting_kota : public QWidget
{
    Q_OBJECT

public:
    explicit setting_kota(QWidget *parent = nullptr);
    static int get_latitude();
    static int get_longitude();
    void setup_database();
    void setup_var();
    void setting_group();
    void insert_group();

private:
    //this for store the from database
    static int latitude;
    static int longitude;

    /*Supporting component*/
    QLabel *country;
    QLabel *kota;
    QLabel *longitude_label;
    QLabel *latitude_label;

    QComboBox *nama_negara;
    QComboBox *nama_kota;
    QVBoxLayout *layout;

    QLineEdit *longitude_edit;
    QLineEdit *latitude_edit;

    QPushButton *oke;


};

#endif // SETTING_KOTA_H
