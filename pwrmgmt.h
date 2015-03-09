#ifndef PWRMGMT_H
#define PWRMGMT_H

#include <pthread.h>
#include <QString>
#include <QFile>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "wait.h"
#include "iniops.h"
#include "safetysys.h"

#define I 128
#define J 3

struct arg_struct {
    QString pwrArray[I][J];
    QString pwrIP;
    QString state;
    int start,end;
    INIOps * ini;
    SafetySys * safety;
};

class PWRMGMT
{
public:
    PWRMGMT(QString src[I][J], QString cFile);
    bool powerOnSystem();
    bool powerOffSystem();
    bool powerOnDS(QString IP, QString pin);
    bool powerOffDS(QString IP, QString pin);
    arg_struct args1,args2;
private:
    QString IP1;
    QString IP2;
    QString SAFETY_CONFIG_FILE;
    INIOps * INI;
    SafetySys * safety;

};

#endif // PWRMGMT_H
