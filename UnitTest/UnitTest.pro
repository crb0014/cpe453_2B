#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T02:17:57
#
#-------------------------------------------------

QT       += widgets sql testlib

TARGET = tst_unittesttest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_unittesttest.cpp \
    ../iniops.cpp \
    ../inireader.cpp \
    ../ini.cpp \
    ../safetysys.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../iniops.h \
    ../config.h \
    ../inireader.h \
    ../ini.h \
    ../safetysys.h

OTHER_FILES += \
    testConfig.ini
