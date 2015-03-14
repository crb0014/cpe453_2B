#ifndef SQLSYS_H
#define SQLSYS_H
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlQueryModel>
#include <QtSql>
#include <QDebug>
#include <QFileDialog>

class SQLSys
{
    public:
        SQLSys(QString dbType = "QMYSQL", QString dbName = "cpe453");
        QString getColor(QString ds); // Gets Color from DS_Key
        bool getStatus(QString ds); // Gets Status from DS_Key
        QStringList getTable(); // Querying all from DS_Status Table
        bool setColor(QString DS, QString color); //Set specified DS_Key to specified color
        bool setStatus(QString DS, bool status); //Set specified DS_key to specified status
        bool isConnected(); // Test if connection was successfull
        bool disconnect(); //

    private:
        QString QuaryDB(QString DS,QString FIELD);
        bool EditField(QString DS, QString FIELD, QString VALUE);
        QSqlDatabase db; // Declaring Database
        QSqlQuery quary;

};
#endif // SQLSYS_H
