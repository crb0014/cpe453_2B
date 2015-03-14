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
#include "safetysys.h"
#include "sqlsys.h"

#define I 128
#define J 3

struct arg_struct {
    QString pwrArray[I][J];
    QString pwrIP;
    QString state;
    int start,end;
    SafetySys * safety;
    SQLSys * sql;
};

class PWRMGMT
{
public:
    PWRMGMT(SQLSys *SQL, QString dsArray[I][J]);
    bool powerOnSystem();
    bool powerOffSystem();
    bool powerOnDS(QString IP, QString pin, QString ds);
    bool powerOffDS(QString IP, QString pin, QString ds);
    arg_struct args1,args2;
private:
    QString IP1;
    QString IP2;
    SafetySys * safety;
    SQLSys * sql;

};

#endif // PWRMGMT_H
