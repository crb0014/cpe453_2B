#include "sqlsys.h"

/**
 * @brief SQLSys::SQLSys
 * @param dbType
 * @param dbName
 */
SQLSys::SQLSys(QString dbType, QString dbName)
{
    model = new QSqlQueryModel;
    db = QSqlDatabase::addDatabase(dbType);
    db.setDatabaseName(dbName);
    if (dbType.contains(("QMYSQL")))
    {
        db.setPort(33156);
        db.setUserName("cpe453student");
        db.setPassword("neicarev");
    }
    db.open();
    quary = QSqlQuery(db);
}

/**
 * @brief SQLSys::GetDSColor
 * @return QString representing the color of the ds
 */
QString SQLSys::getColor(QString ds)
{
    return QuaryDB(ds,"COLOR");
}

/**
 * @brief SQLSys::GetDS_Status
 * @return QString representing the status of the ds
 */
bool SQLSys::getStatus(QString ds)
{
    if (QuaryDB(ds,"STATUS") == "TRUE")
        return true;
    else
        return false;
}

/**
 * @brief SQLSys::Set_Color
 * @param row
 * @param color
 * @return
 */
bool SQLSys::setColor(QString DS, QString color)
{
    return EditField(DS,"COLOR",color);
}

/**
 * @brief SQLSys::Set_Status
 * @param row
 * @param status
 * @return
 */
bool SQLSys::setStatus(QString DS, bool status)
{
    if(status)
        return EditField(DS,"STATUS","TRUE");
    else
        return EditField(DS,"STATUS","FALSE");
}

/**
 * @brief SQLSys::getTable
 * @return QStringList representing table
 */
QStringList SQLSys::getTable()
{
    QStringList results;
    if(db.isValid())
    {
        if(db.isOpen())
        {
            quary.prepare("SELECT * FROM DS_Status;");
            quary.exec();
            if(quary.isActive())
            {
                while (quary.next())
                {
                    results << quary.value(0).toString() << quary.value(1).toString() << quary.value(2).toString() << "\n";
                }
                return results;
            }
        }

    }
    results << "Not Connected";
    return results;
}

/**
 * @brief SQLSys::QuaryDB
 * @param DS is QString of DS number
 * @param FIELD is QString of Field to Display
 * @return QString of the field value for the DS
 */
QString SQLSys::QuaryDB(QString DS, QString FIELD)
{
    QString s="SELECT " + FIELD + " FROM DS_Status WHERE DS='" + DS + "';";
    if(db.isValid())
    {
        if(db.isOpen())
        {
            quary.prepare(s);
            quary.exec();
            if(quary.isActive())
            {
                quary.first();
                return quary.value(0).toString();
            }
        }
    }
    return "false";
}

/**
 * @brief SQLSys::EditField
 * @param DS is the detection section string
 * @param FIELD is the field to update
 * @param VALUE is the value to update the field with
 * @return boolean value for did the operation succede
 */
bool SQLSys::EditField(QString DS, QString FIELD, QString VALUE)
{
    QString s = "UPDATE DS_Status SET " + FIELD + "='" + VALUE + "' WHERE DS='" + DS + "';";
    if(db.isValid())
    {
        if(db.isOpen())
        {
            if(quary.prepare(s))
            {
                if(quary.exec())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @brief SQLSys::isConnected
 * @return boolean
 */
bool SQLSys::isConnected()
{
    if (db.isValid())
    {
        return true;
    }
    else
    {
        qDebug() << "DB is not valid";
        return false;
    }
}
