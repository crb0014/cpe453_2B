#include "mainwindow.h"
#include "ui_mainwindow.h"

void *pthread_progressBar(void *args);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    static QString dsArray[I][J] = {
         {"ds1_1_1","black","54"},
         {"ds1_1_2","black","55"},
         {"ds1_1_3","black","56"},
         {"ds1_1_4","black","57"},
         {"ds1_1_5","black","58"},
         {"ds1_1_6","black","59"},
         {"ds1_1_7","black","60"},
         {"ds1_1_8","black","61"},
         {"ds1_1_9","black","62"},
         {"ds1_1_10","black","63"},
         {"ds1_1_11","black","64"},
         {"ds1_1_12","black","65"},
         {"ds1_1_13","black","66"},
         {"ds1_1_14","black","67"},
         {"ds1_1_15","black","68"},
         {"ds1_1_16","black","69"},
         {"ds1_2_1","black","22"},
         {"ds1_2_2","black","23"},
         {"ds1_2_3","black","24"},
         {"ds1_2_4","black","25"},
         {"ds1_2_5","black","26"},
         {"ds1_2_6","black","27"},
         {"ds1_2_7","black","28"},
         {"ds1_2_8","black","29"},
         {"ds1_2_9","black","30"},
         {"ds1_2_10","black","31"},
         {"ds1_2_11","black","32"},
         {"ds1_2_12","black","33"},
         {"ds1_2_13","black","34"},
         {"ds1_2_14","black","35"},
         {"ds1_2_15","black","36"},
         {"ds1_2_16","black","37"},
         {"ds1_3_1","black","38"},
         {"ds1_3_2","black","39"},
         {"ds1_3_3","black","40"},
         {"ds1_3_4","black","41"},
         {"ds1_3_5","black","42"},
         {"ds1_3_6","black","43"},
         {"ds1_3_7","black","44"},
         {"ds1_3_8","black","45"},
         {"ds1_3_9","black","46"},
         {"ds1_3_10","black","47"},
         {"ds1_3_11","black","48"},
         {"ds1_3_12","black","49"},
         {"ds1_3_13","black","53"},
         {"ds1_3_14","black","11"},
         {"ds1_3_15","black","12"},
         {"ds1_3_16","black","13"},
         {"ds1_4_1","black","0"},
         {"ds1_4_2","black","1"},
         {"ds1_4_3","black","2"},
         {"ds1_4_4","black","3"},
         {"ds1_4_5","black","4"},
         {"ds1_4_6","black","5"},
         {"ds1_4_7","black","6"},
         {"ds1_4_8","black","7"},
         {"ds1_4_9","black","14"},
         {"ds1_4_10","black","15"},
         {"ds1_4_11","black","16"},
         {"ds1_4_12","black","17"},
         {"ds1_4_13","black","18"},
         {"ds1_4_14","black","19"},
         {"ds1_4_15","black","20"},
         {"ds1_4_16","black","21"},
         {"ds2_1_1","black","54"},
         {"ds2_1_2","black","55"},
         {"ds2_1_3","black","56"},
         {"ds2_1_4","black","57"},
         {"ds2_1_5","black","58"},
         {"ds2_1_6","black","59"},
         {"ds2_1_7","black","60"},
         {"ds2_1_8","black","61"},
         {"ds2_1_9","black","62"},
         {"ds2_1_10","black","63"},
         {"ds2_1_11","black","64"},
         {"ds2_1_12","black","65"},
         {"ds2_1_13","black","66"},
         {"ds2_1_14","black","67"},
         {"ds2_1_15","black","68"},
         {"ds2_1_16","black","69"},
         {"ds2_2_1","black","22"},
         {"ds2_2_2","black","23"},
         {"ds2_2_3","black","24"},
         {"ds2_2_4","black","25"},
         {"ds2_2_5","black","26"},
         {"ds2_2_6","black","27"},
         {"ds2_2_7","black","28"},
         {"ds2_2_8","black","29"},
         {"ds2_2_9","black","30"},
         {"ds2_2_10","black","31"},
         {"ds2_2_11","black","32"},
         {"ds2_2_12","black","33"},
         {"ds2_2_13","black","34"},
         {"ds2_2_14","black","35"},
         {"ds2_2_15","black","36"},
         {"ds2_2_16","black","37"},
         {"ds2_3_1","black","38"},
         {"ds2_3_2","black","39"},
         {"ds2_3_3","black","40"},
         {"ds2_3_4","black","41"},
         {"ds2_3_5","black","42"},
         {"ds2_3_6","black","43"},
         {"ds2_3_7","black","44"},
         {"ds2_3_8","black","45"},
         {"ds2_3_9","black","46"},
         {"ds2_3_10","black","47"},
         {"ds2_3_11","black","48"},
         {"ds2_3_12","black","49"},
         {"ds2_3_13","black","53"},
         {"ds2_3_14","black","11"},
         {"ds2_3_15","black","12"},
         {"ds2_3_16","black","13"},
         {"ds2_4_1","black","0"},
         {"ds2_4_2","black","1"},
         {"ds2_4_3","black","2"},
         {"ds2_4_4","black","3"},
         {"ds2_4_5","black","4"},
         {"ds2_4_6","black","5"},
         {"ds2_4_7","black","6"},
         {"ds2_4_8","black","7"},
         {"ds2_4_9","black","14"},
         {"ds2_4_10","black","15"},
         {"ds2_4_11","black","16"},
         {"ds2_4_12","black","17"},
         {"ds2_4_13","black","18"},
         {"ds2_4_14","black","19"},
         {"ds2_4_15","black","20"},
         {"ds2_4_16","black","21"}
    };

    ui->setupUi(this);
    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(0);
    //ops = new INIOps(CONFIG_FILE);
    safety = new SafetySys(CONFIG_FILE);

    pwr = new PWRMGMT(dsArray);
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
