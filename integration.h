#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QDebug>
#include <QHash>

class Integration
{
public:
    Integration();
    QString translate(QString ds);
private:
    QHash<QString, QString> hash;
};

#endif // INTEGRATION_H
