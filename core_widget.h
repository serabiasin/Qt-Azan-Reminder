#ifndef CORE_WIDGET_H
#define CORE_WIDGET_H

/*Bismillahirahmanirrahim*/

#include <QWidget>
#include <QStackedLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>

#include "setting_kota.h"
#include "about_us.h"
#include "jadwal_azan.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QStackedLayout *core_view;
    setting_kota *sett_ui;
    jadwal_azan *jadwal;
    QHBoxLayout *layout_stacked;
    QVBoxLayout *layout_tombol;
    QBoxLayout *tombol_group;
    QGridLayout *buat_rapi;
    QPushButton *tombol[3];
    about_us *about_kita;
    QFrame *sett_frame1; //reserved untuk stacked view
    QFrame *sett_frame2; //reserved untuk tombol widget
private slots:
    void change_to_setting();
    void change_to_jadwal();
    void change_to_about();

};

#endif // CORE_WIDGET_H
