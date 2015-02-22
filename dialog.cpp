#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include "dialog.h"
#include "wait.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextStream>

void *progressBar(void *ptr);


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,14);
    ui->progressBar->setValue(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_powerButton_clicked()
{
    pthread_t thread1;
    const char *message1 = "Thread 1";
    int iret1;

    iret1 = pthread_create( &thread1, NULL, progressBar, (void*) message1);
    if(iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 15; i++)
    {
        ui->progressBar->setValue(i);
        sleep(1);
    }

    ui->progressBar->setWindowTitle("Working");

    if (ui->powerButton->text() == "Power On")
        ui->powerButton->setText("Power Off");
    else
        ui->powerButton->setText("Power On");

    pthread_join(thread1, NULL);
}

void *progressBar(void *ptr) {

    system("touch /dev/useless/temp.txt");
    static bool state = true;

    if (state) {
        system("curl --write-out -o /dev/useless/temp.txt http://192.168.137.2/%on");
        state = false;
    } else {
        system("curl --write-out -o /dev/useless/temp.txt http://192.168.137.2/%off");
        state = true;
    }
    return ptr;
}
