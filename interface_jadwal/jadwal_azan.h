#ifndef JADWAL_AZAN_H
#define JADWAL_AZAN_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFrame>

class jadwal_azan : public QWidget
{
    Q_OBJECT
public:
    explicit jadwal_azan(QWidget *parent = nullptr);
    void set_azan_time(); //this will do something from calculation_azan
    void setting_up();
    void set_variable();

private:
    QLabel *shubuh_time;
    QLabel *dzuhur_time;
    QLabel *ashar_time;
    QLabel *maghrib_time;
    QLabel *isha_time;
    QLabel *time[5]; //this will start from subuh index=0
    QVBoxLayout *view_sholat;
    QVBoxLayout *view_waktu;
    QHBoxLayout *view_estimated;
    QGridLayout *rapi;
    QLabel *estimated;
    QLabel *time_estimated;

};

#endif // JADWAL_AZAN_H
