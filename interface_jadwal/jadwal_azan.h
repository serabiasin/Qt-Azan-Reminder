#ifndef JADWAL_AZAN_H
#define JADWAL_AZAN_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class jadwal_azan : public QWidget
{
    Q_OBJECT
public:
    explicit jadwal_azan(QWidget *parent = nullptr);

signals:

public slots:

private:
    QVBoxLayout *layout;
};

#endif // JADWAL_AZAN_H
