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
    ../safetysys.cpp \
    ../pwrmgmt.cpp \
    ../sqlsys.cpp \
    ../integration.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../iniops.h \
    ../inireader.h \
    ../ini.h \
    ../safetysys.h \
    ../pwrmgmt.h \
    ../sqlsys.h \
    ../dictionary.h \
    ../integration.h

OTHER_FILES += \
    testConfig.ini
