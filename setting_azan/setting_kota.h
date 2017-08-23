#ifndef SETTING_KOTA_H
#define SETTING_KOTA_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

class setting_kota : public QWidget
{
    Q_OBJECT

public:
    explicit setting_kota(QWidget *parent = nullptr);
    static int get_latitude();
    static int get_longitude();

private:
    static int latitude;
    static int longitude;
    QLabel *testing;
    QComboBox *nama_negara;
    QComboBox *nama_kota;

};

#endif // SETTING_KOTA_H
