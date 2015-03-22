#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QAction>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <pthread.h>
#include <QTextBrowser>
#include <time.h>
#include "wait.h"
#include <string.h>
#include <iostream>
#include "popup.h"
#include "inireader.h"
#include "iniops.h"
#include "safetysys.h"
#include "pwrmgmt.h"

#define MAX 128
#define CONFIG_FILE "/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/config.ini"
#define DB_FILE "/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/relaystate.db"


struct pthread_argument {
    QProgressBar * bar;
    int min;
    int max;
    int step;
};

struct pthread_safety_argument {
    SafetySys * safety;
    PWRMGMT * pwr;
    SQLSys * sql;
    INIOps * ops;
    QTextBrowser *txtBrowser;
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_powerButton_clicked();

    void on_actionChange_IP_Address_1_triggered();

    void on_actionChange_IP_Address_2_triggered();

    void on_pushButton_clicked();

    void on_resetButton_clicked();

    void writeTextBrowser();


private:
    Ui::MainWindow *ui;
    INIOps * ops;
    SafetySys * safety;
    PWRMGMT * pwr;
    pthread_argument args;
    pthread_safety_argument safetyArgs;
    pthread_t thread_safety;
    SQLSys * sql;
    QString IP_ADDRESS_ARDUINO_1;
    QString IP_ADDRESS_ARDUINO_2;

};

#endif // MAINWINDOW_H
