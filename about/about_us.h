#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <QWidget>
#include <QLabel>
#include <QTextBrowser>
#include <QGridLayout>

class about_us : public QWidget
{
    Q_OBJECT
public:
    explicit about_us(QWidget *parent = nullptr);
    void set_about();
private:
    QGridLayout *layout;
};

#endif // ABOUT_US_H
