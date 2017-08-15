#ifndef JADWAL_AZAN_H
#define JADWAL_AZAN_H

#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QTableWidget>
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
private:
    QLabel *shubuh_time;
    QLabel *dzuhur_time;
    QLabel *ashar_time;
    QLabel *maghrib_time;
    QLabel *isha_time;
    QGroupBox *layout_rapi;
    QVBoxLayout *view;

};

#endif // JADWAL_AZAN_H
