#include "mainwindow.h"
#include "ui_mainwindow.h"

void *pthread_progressBar(void *args);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(0);
    ops = new INIOps(CONFIG_FILE);
    safety = new SafetySys(CONFIG_FILE);

    pwr = new PWRMGMT(dsArray,CONFIG_FILE);
    ui->stateComboBox->addItem("Enable");
    ui->stateComboBox->addItem("Disable");
    for (int i = 0; i < MAX; i++) {
        if(safety->isDisabled(dsArray[i][0]))
            dsArray[i][1] = "Gray";
        else if (safety->isRed(dsArray[i][0]))
            dsArray[i][1] = "Red";
        else if (safety->isYellow(dsArray[i][0]))
            dsArray[i][1] = "Yellow";
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
    QString mode;
    args.bar = ui->progressBar;
    args.min = 0;
    args.max = 8;
    args.step = 1;

    pthread_t thread1;
    int iret1;
    if (ui->powerButton->text() == "Power On")
        mode = "off";
    else
        mode = "on";

    pwr = new PWRMGMT(dsArray,CONFIG_FILE);
    iret1 = pthread_create(&thread1, NULL, pthread_progressBar, (void*) &args);
    if(iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }
    if (mode == "off")
        pwr->powerOnSystem();
    else
        pwr->powerOffSystem();

    pthread_join(thread1, NULL);
    if (ui->powerButton->text() == "Power On")
        ui->powerButton->setText("Power Off");
    else
        ui->powerButton->setText("Power On");

    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(1);
    writeTextBrowser();
}

/**
 * @brief MainWindow::writeTextBrowser
 */
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
    ops = new INIOps(CONFIG_FILE);
    popup * myPopup = new popup(1,dsArray,this);
    myPopup->resize(300,125);
    myPopup->setWindowTitle("IP Change Arduino 1");
    myPopup->exec();
    IP_ADDRESS_ARDUINO_1 = ops->getIPArduino1();
}

void MainWindow::on_actionChange_IP_Address_2_triggered()
{
    ops = new INIOps(CONFIG_FILE);
    popup * myPopup = new popup(2,dsArray,this);
    myPopup->resize(300,125);
    myPopup->setWindowTitle("IP Change Arduino 2");
    myPopup->exec();
    IP_ADDRESS_ARDUINO_2 = ops->getIPArduino2();
}

/**
 * @brief MainWindow::on_pushButton_clicked
 */
void MainWindow::on_pushButton_clicked()
{
    ops = new INIOps(CONFIG_FILE);
    safety = new SafetySys(CONFIG_FILE);
    pwr = new PWRMGMT(dsArray,CONFIG_FILE);
    QString ds_state,IP,IP1,IP2;
    IP1 = ops->getIPArduino1();
    IP2 = ops->getIPArduino2();
    int position;
    position = ui->dsComboBox->currentIndex();
    ds_state = ui->stateComboBox->currentText();
    ui->progressBar->setValue(0);
    QStringList stringPieces = dsArray[position][0].split("_");

    if (stringPieces[0] == "ds1")
        IP = ops->getIPArduino1();
    else
        IP = ops->getIPArduino2();


    if (ds_state == "Disable")
    {
        if (safety->isSafe(dsArray[position][0]))
        {
            dsArray[position][1] = "Gray";
            ops->writeINI(ops->getIPArduino1(),ops->getIPArduino2(),dsArray);
            pwr->powerOffDS(IP,dsArray[position][2]);
        }
    }
    else
    {
        if (safety->isSafe((dsArray[position][0])))
        {
            dsArray[position][1] = "Green";
            ops->writeINI(ops->getIPArduino1(),ops->getIPArduino2(),dsArray);
            pwr->powerOnDS(IP,dsArray[position][2]);
        }
    }

    ops->writeINI(IP1,IP2,dsArray);
    writeTextBrowser();
    ui->progressBar->setValue(1);
}


void MainWindow::on_resetButton_clicked()
{
    ops = new INIOps(CONFIG_FILE);
    safety = new SafetySys(CONFIG_FILE);
    QString ip1,ip2;
    ip1 = ops->getIPArduino1();
    ip2 = ops->getIPArduino2();
    pwr = new PWRMGMT(dsArray,CONFIG_FILE);
    pwr->powerOffSystem();
    for (int i = 0; i < I; i++)
    {
        if (safety->isSafe(dsArray[i][0]))
        {
            dsArray[i][1] = "Black";
        }
    }
    ops->writeINI(ip1,ip2,dsArray);
    ui->powerButton->setText("Power On");
    writeTextBrowser();
}


void *pthread_progressBar(void *args)
{
    pthread_argument *arg = (pthread_argument*) args;
    arg->bar->setRange(arg->min,arg->max);
    arg->bar->setValue(arg->min);
    for (int i = arg->min; i < arg->max + 1; i+=arg->step)
    {
        arg->bar->setValue(i);
        sleep(1);
    }
    pthread_exit(NULL);
}
