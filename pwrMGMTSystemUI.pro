#-------------------------------------------------
#
# Project created by QtCreator 2015-02-21T14:09:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pwrMGMTSystemUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    popup.cpp \
    inireader.cpp \
    ini.cpp

HEADERS  += mainwindow.h \
    popup.h \
    inireader.h \
    ini.h \
    config.h

FORMS    += mainwindow.ui \
    popup.ui

OTHER_FILES += \
    config.ini
