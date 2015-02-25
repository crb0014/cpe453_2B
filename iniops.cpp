#include "iniops.h"
#include <QDebug>

/**
 * @brief INIOps::INIOps
 * @param QString of config file name
 */
INIOps::INIOps(QString str)
{
   reader = new INIReader(str.toStdString());
   configFile = str;
}

/**
 * @brief INIOps::writeINI
 * @return boolean value true if error or false if not
 */
bool INIOps::checkForError()
{
    if (reader->ParseError() < 0)
        return true;
    else
        return false;
}

/**
 * @brief INIOps::writeINI : writes all data to the config file
 * @return boolean value true if error or false if not
 */
bool INIOps::writeINI(QString IP1, QString IP2, QString Array[I][J])
{
    remove(configFile.toStdString().c_str());
    QFile file(configFile);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return true;

    QTextStream out(&file);

    out << "; config file for pwrMGMTUI\n"
        << "\n"
        << "[arduino]\n"
        << "arduinoOneIP = " << IP1 << "\n"
        << "arduinoTwoIP = " << IP2 << "\n"
        << "\n"
        << "[disabled]\n";

    for (int i = 0; i < I; i++)
        if (Array[i][1] == "Gray")
            out << Array[i][0] << " = disabled\n";
        else if (Array[i][1] == "Red")
            out << Array[i][0] << " = Red Status\n";
        else if (Array[i][1] == "Yellow")
            out << Array[i][0] << " = Yellow Status\n";
    file.close();
    return false;
}

/**
 * @brief INIOps::getIPArduino1
 * @return IP Address of Arduino Board 1
 */
QString INIOps::getIPArduino1()
{
    if(checkForError())
        return "Error Occured Opening INI";
    else
        return reader->Get("arduino","arduinoOneIP","None Provided").c_str();
}

/**
 * @brief INIOps::getIPArduino2
 * @return IP Address of Arduino Board 2
 */
QString INIOps::getIPArduino2()
{
    if(checkForError())
        return "Error Occured Opening INI";
    else
        return reader->Get("arduino","arduinoTwoIP","None Provided").c_str();
}
