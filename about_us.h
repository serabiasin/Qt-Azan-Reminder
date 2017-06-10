#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class about_us : public QWidget
{
    Q_OBJECT
public:
    explicit about_us(QWidget *parent = nullptr);

private:
    QLabel *test;
};

#endif // ABOUT_US_H
