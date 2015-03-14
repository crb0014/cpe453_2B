#include "popup.h"
#include "ui_popup.h"
#include <QDebug>

QString ipAddrHolder;
int arduinoNum;
bool ipSet = false;

popup::popup(int arduino, QString Array[I][J], QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
    ops = new INIOps(CONFIG_FILE);
    if (arduino == 1)
        ui->curentAddr->setText(ops->getIPArduino1());
    else
        ui->curentAddr->setText(ops->getIPArduino2());
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++)
            array [i][j] = Array[i][j];
    arduinoNum = arduino;
    IP_ADDRESS_ARDUINO_1 = ops->getIPArduino1();
    IP_ADDRESS_ARDUINO_2 = ops->getIPArduino2();

}

/**
 * @brief popup::~popup
 */
popup::~popup()
{
    delete ui;
}

/**
 * @brief popup::on_newAddress_textEdited
 * @param arg1
 */
void popup::on_newAddress_textEdited()
{
    QRegExp ipValidator( "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}" );
    QValidator *validator = new QRegExpValidator(ipValidator, this);
    ui->newAddress->setValidator(validator);
}

/**
 * @brief popup::on_newAddress_editingFinished
 */
void popup::on_newAddress_editingFinished()
{
    ipSet = true;
}

/**
 * @brief popup::on_setButton_clicked
 */
void popup::on_setButton_clicked()
{
    if(ipSet)
    {
        if(arduinoNum == 1)
        {
            if (IP_ADDRESS_ARDUINO_2.compare(ui->newAddress->text()))
            {
                IP_ADDRESS_ARDUINO_1 = ui->newAddress->text();
                ui->curentAddr->setText(IP_ADDRESS_ARDUINO_1);
                ops->writeINI(IP_ADDRESS_ARDUINO_1,IP_ADDRESS_ARDUINO_2,array);
            }
        } else {
            if (IP_ADDRESS_ARDUINO_1.compare(ui->newAddress->text()))
            {
                IP_ADDRESS_ARDUINO_2 = ui->newAddress->text();
                ui->curentAddr->setText(IP_ADDRESS_ARDUINO_2);
                ops->writeINI(IP_ADDRESS_ARDUINO_1,IP_ADDRESS_ARDUINO_2,array);
            }
        }
        ipSet = false;
    }
}

/**
 * @brief popup::on_closeButton_clicked
 */
void popup::on_closeButton_clicked()
{
    this->close();
}
