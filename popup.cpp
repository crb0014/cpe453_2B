#include "popup.h"
#include "ui_popup.h"
#include "config.h"
#include <QDebug>

QString ipAddrHolder;
int arduinoNum;
bool ipSet = false;

popup::popup(QString addr,int arduino, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
    ui->curentAddr->setText(addr);
    arduinoNum = arduino;
    readIP_ADDRESSES();
}

popup::~popup()
{
    delete ui;
}

void popup::on_newAddress_textEdited(const QString &arg1)
{
    QRegExp ipValidator( "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}" );
    QValidator *validator = new QRegExpValidator(ipValidator, this);
    ui->newAddress->setValidator(validator);
}

void popup::writeINI()
{
    remove(CONFIG_FILE);
    QFile file(CONFIG_FILE);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream out(&file);

    out << "; config file for pwrMGMTUI\n"
        << "\n"
        << "[arduino]\n"
        << "arduinoOneIP = " << IP_ADDRESS_ARDUINO_1 << "\n"
        << "arduinoTwoIP = " << IP_ADDRESS_ARDUINO_2 << "\n"
        << "\n"
        << "[disabled]\n";
    for (int i = 0; i < MAX; i++)
        if (dsArray[i][1] == "Gray")
            out << dsArray[i][0] << " = disabled\n";
    file.close();
}

void popup::readIP_ADDRESSES()
{
    INIReader reader(CONFIG_FILE);
    if(reader.ParseError() < 0)
    {
        qDebug() << "Can't load config file";
    }

    IP_ADDRESS_ARDUINO_1 = reader.Get("arduino","arduinoOneIP","None Provided").c_str();
    IP_ADDRESS_ARDUINO_2 = reader.Get("arduino","arduinoTwoIP","None Provided").c_str();
}

void popup::on_newAddress_editingFinished()
{
    ipSet = true;
}

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
                writeINI();
            }
        } else {
            if (IP_ADDRESS_ARDUINO_1.compare(ui->newAddress->text()))
            {
                IP_ADDRESS_ARDUINO_2 = ui->newAddress->text();
                ui->curentAddr->setText(IP_ADDRESS_ARDUINO_2);
                writeINI();
            }
        }

        ipSet = false;
    }
}
void popup::on_closeButton_clicked()
{
    this->close();
}
