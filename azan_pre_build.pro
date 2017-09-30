#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T21:03:42
#
#-------------------------------------------------

QT       += core gui webkitwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = azan_pre_build
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    about/about_us.cpp \
    interface_jadwal/jadwal_azan.cpp \
    setting_azan/setting_kota.cpp \
    core_widget.cpp \
    calculation_azan/azan_calculation.cpp

HEADERS += \
    about/about_us.h \
    calculation_azan/azan_calculation.h \
    setting_azan/setting_kota.h \
    interface_jadwal/jadwal_azan.h \
    core_widget.h \
    calculation_azan/azan_calculation.h

SUBDIRS += \
    azan_pre_build.pro

DISTFILES += \
    database_city.sqlite \
    LICENSE.md \
    Credited To \
    azan_pre_build.pro.user \

RESOURCES += \
    icon/icon_pack.qrc \
    about/about_resource.qrc
