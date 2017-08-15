#ifndef JADWAL_AZAN_H
#define JADWAL_AZAN_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QString>

class jadwal_azan : public QWidget
{
    Q_OBJECT
public:
    explicit jadwal_azan(QWidget *parent = nullptr);
    void set_azan_time();
    void setting_up();
    inline void set_variable();

private:
    QLabel *shubuh_time;
    QLabel *dzuhur_time;
    QLabel *ashar_time;
    QLabel *maghrib_time;
    QLabel *isha_time;
    QLabel *time[5]; //this will start from subuh index=0
    QVBoxLayout *view_sholat;
    QVBoxLayout *view_waktu;
    QGridLayout *rapi;

};

#endif // JADWAL_AZAN_H
