#ifndef INIOPS_H
#define INIOPS_H

#include <QString>
#include <QFile>
#include "inireader.h"

#define I 128
#define J 3

class INIOps
{
    INIReader * reader;
    QString configFile;

public:
    INIOps(QString str);
    QString getIPArduino1();
    QString getIPArduino2();
    bool writeINI(QString IP1, QString IP2, QString Array[I][J]);

private:
    bool checkForError();

};

#endif // INIOPS_H
