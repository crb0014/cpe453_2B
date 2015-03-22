#include "mainwindow.h"
#include "ui_mainwindow.h"

// Global Shared Memory
bool safety_thread_run = false;

static QString dsArray[I][J] = {
    {"1_1","black","54"},
    {"1_2","black","55"},
    {"1_3","black","56"},
    {"1_4","black","57"},
    {"1_5","black","58"},
    {"1_6","black","59"},
    {"1_7","black","60"},
    {"1_8","black","61"},
    {"1_9","black","62"},
    {"1_10","black","63"},
    {"1_11","black","64"},
    {"1_12","black","65"},
    {"1_13","black","66"},
    {"1_14","black","67"},
    {"1_15","black","68"},
    {"1_16","black","69"},
    {"2_1","black","22"},
    {"2_2","black","23"},
    {"2_3","black","24"},
    {"2_4","black","25"},
    {"2_5","black","26"},
    {"2_6","black","27"},
    {"2_7","black","28"},
    {"2_8","black","29"},
    {"2_9","black","30"},
    {"2_10","black","31"},
    {"2_11","black","32"},
    {"2_12","black","33"},
    {"2_13","black","34"},
    {"2_14","black","35"},
    {"2_15","black","36"},
    {"2_16","black","37"},
    {"3_1","black","38"},
    {"3_2","black","39"},
    {"3_3","black","40"},
    {"3_4","black","41"},
    {"3_5","black","42"},
    {"3_6","black","43"},
    {"3_7","black","44"},
    {"3_8","black","45"},
    {"3_9","black","46"},
    {"3_10","black","47"},
    {"3_11","black","48"},
    {"3_12","black","49"},
    {"3_13","black","53"},
    {"3_14","black","11"},
    {"3_15","black","12"},
    {"3_16","black","13"},
    {"4_1","black","0"},
    {"4_2","black","1"},
    {"4_3","black","2"},
    {"4_4","black","3"},
    {"4_5","black","4"},
    {"4_6","black","5"},
    {"4_7","black","6"},
    {"4_8","black","7"},
    {"4_9","black","14"},
    {"4_10","black","15"},
    {"4_11","black","16"},
    {"4_12","black","17"},
    {"4_13","black","18"},
    {"4_14","black","19"},
    {"4_15","black","20"},
    {"4_16","black","21"},
    {"5_1","black","54"},
    {"5_2","black","55"},
    {"5_3","black","56"},
    {"5_4","black","57"},
    {"5_5","black","58"},
    {"5_6","black","59"},
    {"5_7","black","60"},
    {"5_8","black","61"},
    {"5_9","black","62"},
    {"5_10","black","63"},
    {"5_11","black","64"},
    {"5_12","black","65"},
    {"5_13","black","66"},
    {"5_14","black","67"},
    {"5_15","black","68"},
    {"5_16","black","69"},
    {"6_1","black","22"},
    {"6_2","black","23"},
    {"6_3","black","24"},
    {"6_4","black","25"},
    {"6_5","black","26"},
    {"6_6","black","27"},
    {"6_7","black","28"},
    {"6_8","black","29"},
    {"6_9","black","30"},
    {"6_10","black","31"},
    {"6_11","black","32"},
    {"6_12","black","33"},
    {"6_13","black","34"},
    {"6_14","black","35"},
    {"6_15","black","36"},
    {"6_16","black","37"},
    {"7_1","black","38"},
    {"7_2","black","39"},
    {"7_3","black","40"},
    {"7_4","black","41"},
    {"7_5","black","42"},
    {"7_6","black","43"},
    {"7_7","black","44"},
    {"7_8","black","45"},
    {"7_9","black","46"},
    {"7_10","black","47"},
    {"7_11","black","48"},
    {"7_12","black","49"},
    {"7_13","black","53"},
    {"7_14","black","11"},
    {"7_15","black","12"},
    {"7_16","black","13"},
    {"8_1","black","0"},
    {"8_2","black","1"},
    {"8_3","black","2"},
    {"8_4","black","3"},
    {"8_5","black","4"},
    {"8_6","black","5"},
    {"8_7","black","6"},
    {"8_8","black","7"},
    {"8_9","black","14"},
    {"8_10","black","15"},
    {"8_11","black","16"},
    {"8_12","black","17"},
    {"8_13","black","18"},
    {"8_14","black","19"},
    {"8_15","black","20"},
    {"8_16","black","21"}
};

void *pthread_progressBar(void *args);
void *pthread_safetySys(void *args);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int iret_safety;
    ui->setupUi(this);
    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(0);
    safety = new SafetySys();
    ops = new INIOps(CONFIG_FILE);


    sql = new SQLSys("QSQLITE",DB_FILE);
    pwr = new PWRMGMT(sql,dsArray);
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
    safetyArgs.pwr = pwr;
    safetyArgs.safety = safety;
    safetyArgs.sql = sql;
    safetyArgs.txtBrowser = ui->textBrowser;
    safetyArgs.ops = ops;
    iret_safety = pthread_create(&thread_safety, NULL, pthread_safetySys, (void*) &args);
    if(iret_safety) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n",iret_safety);
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief MainWindow::~MainWindow deconstructor
 */
MainWindow::~MainWindow()
{
    safety_thread_run = false;
    pthread_join(thread_safety, NULL);
    delete ui;
}

/**
 * @brief MainWindow::on_powerButton_clicked power on/off system
 */
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

    pwr = new PWRMGMT(sql,dsArray);
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
 * @brief MainWindow::writeTextBrowser to current status of relay
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
        str1 = dsArray[i][0] + "                      |                " + sql->getColor(dsArray[i][0]);
        if(sql->getColor(dsArray[i][0])=="red") ui->textBrowser->setTextColor(QColor("red"));
        else if(sql->getColor(dsArray[i][0])=="yellow") ui->textBrowser->setTextColor(QColor("orange"));
        else if(sql->getColor(dsArray[i][0])=="green") ui->textBrowser->setTextColor(QColor("green"));
        else if(sql->getColor(dsArray[i][0]) == "gray") ui->textBrowser->setTextColor("gray");
        else ui->textBrowser->setTextColor("black");
        ui->textBrowser->append(str1);
        ui->textBrowser->append("------------------------------------------------------------");
    }
}

/**
 * @brief MainWindow::on_actionChange_IP_Address_1_triggered
 *        Popup to change IP address 1
 */
void MainWindow::on_actionChange_IP_Address_1_triggered()
{
    ops = new INIOps(CONFIG_FILE);
    popup * myPopup = new popup(1,dsArray,this);
    myPopup->resize(300,125);
    myPopup->setWindowTitle("IP Change Arduino 1");
    myPopup->exec();
    IP_ADDRESS_ARDUINO_1 = ops->getIPArduino1();
}

/**
 * @brief MainWindow::on_actionChange_IP_Address_2_triggered
 *        Popup to change IP address 2
 */
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
 * @brief MainWindow::on_pushButton_clicked - power on/off selected detection seciton
 */
void MainWindow::on_pushButton_clicked()
{
    ops = new INIOps(CONFIG_FILE);
    safety = new SafetySys();
    pwr = new PWRMGMT(sql,dsArray);
    QString ds_state,IP,IP1,IP2;
    IP1 = ops->getIPArduino1();
    IP2 = ops->getIPArduino2();
    int position;
    position = ui->dsComboBox->currentIndex();
    ds_state = ui->stateComboBox->currentText();
    ui->progressBar->setValue(0);
    QStringList stringPieces = dsArray[position][0].split("_");

    if (stringPieces[0] == "1" || stringPieces[0] == "2" || stringPieces[0] == "3" || stringPieces[0] =="4")
        IP = ops->getIPArduino1();
    else
        IP = ops->getIPArduino2();


    if (ds_state == "Disable")
    {
        if (safety->isSafe(dsArray[position][0]))
        {
            dsArray[position][1] = "Gray";
            ops->writeINI(ops->getIPArduino1(),ops->getIPArduino2(),dsArray);
            pwr->powerOffDS(IP,dsArray[position][2],dsArray[position][0]);
        }
    }
    else
    {
        if (safety->isSafe((dsArray[position][0])))
        {
            dsArray[position][1] = "Green";
            ops->writeINI(ops->getIPArduino1(),ops->getIPArduino2(),dsArray);
            pwr->powerOnDS(IP,dsArray[position][2],dsArray[position][0]);
        }
    }

    ops->writeINI(IP1,IP2,dsArray);
    writeTextBrowser();
    ui->progressBar->setValue(1);
}

/**
 * @brief MainWindow::on_resetButton_clicked - resets the status of all arduino pins to powered off
 */
void MainWindow::on_resetButton_clicked()
{
    ops = new INIOps(CONFIG_FILE);
    safety = new SafetySys();
    QString ip1,ip2;
    ip1 = ops->getIPArduino1();
    ip2 = ops->getIPArduino2();
    pwr = new PWRMGMT(sql,dsArray);
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

/**
 * @brief pthread_progressBar - pthread used to allow the progress bar to update in parralell
 * @param args
 * @return
 */
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

/**
 * @brief pthread_safetySys - pthread used to run the safety system in the background
 * @param args
 * @return
 */
void *pthread_safetySys(void *args)
{
    pthread_safety_argument *arg = (pthread_safety_argument*) args;
    QString IP1 = arg->ops->getIPArduino1();
    QString IP2 = arg->ops->getIPArduino2();
    safety_thread_run = true;
    bool change = false;
    while (safety_thread_run)
    {
        sleep(1);
        for (int i = 0; i < MAX; i++)
        {
            if (!arg->safety->isSafe(dsArray[i][0]))
            {
                change = true;
                if (i < 64)
                    arg->pwr->powerOffDS(IP1,dsArray[i][2],dsArray[i][1]);
                else
                    arg->pwr->powerOffDS(IP2,dsArray[i][2],dsArray[i][1]);
            }
            if (change)
            {
                QString str1;
                arg->txtBrowser->clear();
                arg->txtBrowser->append("------------------------------------------------------------");
                arg->txtBrowser->append("Detection Section  |                 Status                 ");
                arg->txtBrowser->append("------------------------------------------------------------");
                for (int i = 0; i < MAX; i++)
                {
                    str1 = dsArray[i][0] + "                      |                " + arg->sql->getColor(dsArray[i][0]);
                    if(arg->sql->getColor(dsArray[i][0])=="red") arg->txtBrowser->setTextColor(QColor("red"));
                    else if(arg->sql->getColor(dsArray[i][0])=="yellow") arg->txtBrowser->setTextColor(QColor("orange"));
                    else if(arg->sql->getColor(dsArray[i][0])=="green") arg->txtBrowser->setTextColor(QColor("green"));
                    else if(arg->sql->getColor(dsArray[i][0]) == "gray") arg->txtBrowser->setTextColor("gray");
                    else arg->txtBrowser->setTextColor("black");
                    arg->txtBrowser->append(str1);
                    arg->txtBrowser->append("------------------------------------------------------------");
                }
            }
        }
    }

    pthread_exit(NULL);

}
