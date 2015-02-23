#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <string.h>
#include <iostream>
#include "config.h"

void *arduinoONE(void *ptr);
void *arduinoTWO(void *ptr);
QString GetStdoutFromCommand(QString cmd);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(0);
    readIP_ADDRESSES();
    ui->stateComboBox->addItem("Enable");
    ui->stateComboBox->addItem("Disable");
    for (int i = 0; i < MAX; i++) {
        if(isDisabled(dsArray[i][0]) != "false")
        {
            dsArray[i][1] = "Gray";
        }
        ui->dsComboBox->addItem(dsArray[i][0]);
    }
    writeTextBrowser();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_powerButton_clicked()
{
    pthread_t thread1;
    const char *message1 = "Thread 1";
    int iret1;
    ui->progressBar->setRange(0,7);
    ui->progressBar->setValue(0);

    iret1 = pthread_create( &thread1, NULL, arduinoONE, (void*) message1);
    if(iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < 8; i++)
    {
        ui->progressBar->setValue(i);
        sleep(1);
    }

    if (ui->powerButton->text() == "Power On")
        ui->powerButton->setText("Power Off");
    else
        ui->powerButton->setText("Power On");

    pthread_join(thread1, NULL);
    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(1);
    writeTextBrowser();

}

void MainWindow::readIP_ADDRESSES()
{
    INIReader reader(CONFIG_FILE);
    if(reader.ParseError() < 0)
    {
        qDebug() << "Can't load config file";
    }

    IP_ADDRESS_ARDUINO_1 = reader.Get("arduino","arduinoOneIP","None Provided").c_str();
    IP_ADDRESS_ARDUINO_2 = reader.Get("arduino","arduinoTwoIP","None Provided").c_str();
}

QString MainWindow::isDisabled(QString str)
{
    INIReader reader(CONFIG_FILE);
    if(reader.ParseError() < 0)
        qDebug() << "Can't load config file.";

    return reader.Get("disabled",str.toStdString().c_str(),"false").c_str();
}

void MainWindow::writeINI()
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

void MainWindow::writeTextBrowser()
{
    QString str1;
    ui->textBrowser->clear();
    ui->textBrowser->append("------------------------------------------------------------");
    ui->textBrowser->append("Detection Section  |                 Status                 ");
    ui->textBrowser->append("------------------------------------------------------------");
    for (int i = 0; i < MAX; i++)
    {
        str1 = dsArray[i][0] + "                  |                " + dsArray[i][1];
        if(dsArray[i][1] == "Red") ui->textBrowser->setTextColor(QColor("red"));
        else if(dsArray[i][1] == "Yellow") ui->textBrowser->setTextColor(QColor("orange"));
        else if(dsArray[i][1] == "Green") ui->textBrowser->setTextColor(QColor("green"));
        else if(dsArray[i][1] == "Gray") ui->textBrowser->setTextColor("gray");
        else ui->textBrowser->setTextColor("black");
        ui->textBrowser->append(str1);
        ui->textBrowser->append("------------------------------------------------------------");
    }
}



void MainWindow::on_actionChange_IP_Address_1_triggered()
{
    popup * myPopup = new popup(IP_ADDRESS_ARDUINO_1,1,this);
    myPopup->resize(300,125);
    myPopup->setWindowTitle("IP Change Arduino 1");
    myPopup->exec();
}

void MainWindow::on_actionChange_IP_Address_2_triggered()
{
    popup * myPopup = new popup(IP_ADDRESS_ARDUINO_2,2,this);
    myPopup->resize(300,125);
    myPopup->setWindowTitle("IP Change Arduino 2");
    myPopup->exec();
}

QString GetStdoutFromCommand(QString cmd)
{
    QString data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.toUtf8(), "r");
    if (stream) {
    while (!feof(stream))
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}

void MainWindow::on_pushButton_clicked()
{
    QString ds_state;
    int position;
    position = ui->dsComboBox->currentIndex();
    ds_state = ui->stateComboBox->currentText();
    ui->progressBar->setValue(0);
    QStringList stringPieces = dsArray[position][0].split("_");
    QString powerOff;
    QString powerOn;

    if (stringPieces[0] == "ds1")
    {
        powerOff = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "/?" + dsArray[position][2] + "-off";
        powerOn = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "/?" + dsArray[position][2] + "-on";
    }
    else
    {
        powerOff = "curl -s http://" + IP_ADDRESS_ARDUINO_2 + "/?" + dsArray[position][2] + "-off";
        powerOn = "curl -s http://" + IP_ADDRESS_ARDUINO_2 + "/?" + dsArray[position][2] + "-on";
    }

    if (ds_state == "Disable")
    {
        dsArray[position][1] = "Gray";
        writeINI();
        GetStdoutFromCommand(powerOff);

    }
    else
    {
        //safetyCheck(position);  // function call to check the safety of detection section
        dsArray[position][1] = "Green";
        writeINI();
        GetStdoutFromCommand(powerOn);
    }
    writeTextBrowser();
    ui->progressBar->setValue(1);
}

void MainWindow::safetyCheck(int position)
{
    // Add Code to check for broken rules related to detection section
    dsArray[position][1] = "Green";
}

/////////////////////////////////////////////////////////////////////////////////////
void *arduinoONE(void *ptr) {

    static bool state = true;
    QString powerOn;// = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "/%on";
    QString powerOff;//f = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "/%off";

    if (state) {
        for (int i = 0; i < MAX/2; i++)
        {
            if (dsArray[i][1] == "Black")
            {
                powerOn = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "?" + dsArray[i][2] + "-on";
                dsArray[i][1] = "Green";
                //sleep(1);
            }
            GetStdoutFromCommand(powerOn);
        }
        state = false;
    } else {
        for (int i = 0; i < MAX/2; i++)
        {
            if (dsArray[i][1] == "Green")
            {
                powerOff = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "?" + dsArray[i][2] + "-off";
                dsArray[i][1] = "Black";
            }
            GetStdoutFromCommand(powerOff);
        }
        state = true;
    }
    return ptr;
}

void *arduinoTWO(void *ptr) {

    static bool state = true;
    QString powerOn = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "/%on";
    QString powerOff = "curl -s http://" + IP_ADDRESS_ARDUINO_1 + "/%off";

    if (state) {
        GetStdoutFromCommand(powerOn);
        state = false;
    } else {
        GetStdoutFromCommand(powerOff);
        state = true;
    }
    return ptr;
}
