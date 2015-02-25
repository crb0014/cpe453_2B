#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <QAction>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include "wait.h"
#include "popup.h"
#include "inireader.h"
#include "iniops.h"

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

private:
    Ui::MainWindow *ui;
    INIOps * ops;
    void writeTextBrowser();
    void safetyCheck(int position);
    QString isDisabled(QString str);
};

#endif // MAINWINDOW_H
