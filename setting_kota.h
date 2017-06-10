#ifndef SETTING_KOTA_H
#define SETTING_KOTA_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class setting_kota : public QWidget
{
    Q_OBJECT
public:
    explicit setting_kota(QWidget *parent = nullptr);

private:
QLabel *testing;
};

#endif // SETTING_KOTA_H
