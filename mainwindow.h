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
#include <time.h>
#include "wait.h"
#include <string.h>
#include <iostream>
#include "popup.h"
#include "inireader.h"
#include "iniops.h"
#include "safetysys.h"
#include "pwrmgmt.h"
#include "config.h"

struct pthread_argument {
    QProgressBar * bar;
    int min;
    int max;
    int step;
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

private:
    Ui::MainWindow *ui;
    INIOps * ops;
    SafetySys * safety;
    PWRMGMT * pwr;
    pthread_argument args;
    void writeTextBrowser();

};

#endif // MAINWINDOW_H
