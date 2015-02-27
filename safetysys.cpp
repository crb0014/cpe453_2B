#include "safetysys.h"

SafetySys::SafetySys(QString configFile)
{
    fileName = configFile;
}

/**
 * @brief SafetySys::safetyCheck
 * @param str - the detection section to check
 * @return boolean true if is safe or false is not
 */
bool SafetySys::isSafe(QString str)
{
    if (isRed(str)) {return false;}
    else if (isYellow(str)) {return false;}
    else return true;
}

/**
 * @brief SafetySys::isDisabled
 * @param str - the detection section to check
 * @return boolean true if is red or false if not
 */
bool SafetySys::isDisabled(QString str)
{
    INIReader reader(fileName.toStdString());
    if(reader.ParseError() < 0)
        qDebug() << "Can't load config file.";

    QString holderString = reader.Get("disabled",str.toStdString().c_str(),"false").c_str();

    if (holderString.compare("disabled"))
        return false;
    else
        return true;
}

/**
 * @brief SafetySys::isRed
 * @param str - the detection section to check
 * @return boolean true if is red or false if not
 */
bool SafetySys::isRed(QString str)
{
    INIReader reader(fileName.toStdString());
    if(reader.ParseError() < 0)
        qDebug() << "Can't load config file.";

    QString holderString = reader.Get("disabled",str.toStdString().c_str(),"false").c_str();

    if (holderString.compare("red"))
        return false;
    else
        return true;
}

/**
 * @brief SafetySys::isYellow
 * @param str - the detection section to check
 * @return boolean true if is yellow or false if not
 */
bool SafetySys::isYellow(QString str)
{
    INIReader reader(fileName.toStdString());
    if(reader.ParseError() < 0)
        qDebug() << "Can't load config file.";

    QString holderString = reader.Get("disabled",str.toStdString().c_str(),"false").c_str();

    if (holderString.compare("yellow"))
        return false;
    else
        return true;
}
