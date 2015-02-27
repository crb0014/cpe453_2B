#ifndef SAFETYSYS_H
#define SAFETYSYS_H

#include <QString>
#include <QDebug>
#include "inireader.h"
#include "iniops.h"

#define I 128
#define J 3

class SafetySys
{
public:
    SafetySys(QString ConfigFile);
    bool isSafe(QString str);
    bool isDisabled(QString str);
    bool isRed(QString str);
    bool isYellow(QString str);

private:
    INIReader * reader;
    QString DSARRAY[I][J];
    QString IP1;
    QString IP2;
    QString fileName;
};

#endif // SAFETYSYS_H
