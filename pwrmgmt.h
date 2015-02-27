#ifndef PWRMGMT_H
#define PWRMGMT_H

#include <pthread.h>
#include <QString>
#include <QFile>
#include <stdio.h>
#include <stdlib.h>

#define I 128
#define J 3

class PWRMGMT
{
public:
    PWRMGMT(QString src[I][J], QString ip1, QString ip2);
private:
    QString array[I][J];
    QString IP1;
    QString IP2;
};

#endif // PWRMGMT_H
