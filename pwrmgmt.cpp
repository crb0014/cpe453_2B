#include "pwrmgmt.h"
#include <QDebug>

void *arduino(void *ptr);
QString GetStdoutFromCommand(QString cmd);

/**
 * @brief PWRMGMT::PWRMGMT
 */
PWRMGMT::PWRMGMT(QString src[I][J], QString cFile)
{
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++)
        {
            args1.pwrArray[i][j] = src[i][j];
            args2.pwrArray[i][j] = src[i][j];
        }
    SAFETY_CONFIG_FILE = cFile;
    INI = new INIOps(SAFETY_CONFIG_FILE);
    safety = new SafetySys(SAFETY_CONFIG_FILE);
    IP1 = INI->getIPArduino1();
    IP2 = INI->getIPArduino2();
    args1.pwrIP = IP1;
    args2.pwrIP = IP2;
    args1.start = 0;
    args2.start = 64;
    args1.end = 64;
    args2.end = 128;
    args1.ini = INI;
    args2.ini = INI;
    args1.safety = safety;
    args2.safety = safety;
}

/**
 * @brief PWRMGMT::powerOnSystem
 * @return
 */
bool PWRMGMT::powerOnSystem()
{
    bool *state[2];
    state[0] = false;
    state[1] = false;
    pthread_t thread1, thread2;
    int iret1, iret2;

    args1.state = "on";
    iret1 = pthread_create(&thread1, NULL, arduino, (void*) &args1);
    if(iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n",iret1);
        return false;
    }

    //args2.state = "on";
    //iret2 = pthread_create(&thread2, NULL, arduino, (void*) &args2);
    //if(iret2) {
    //    fprintf(stderr, "Error - pthread_create() return code: %d\n",iret2);
    //    return false;
    //}

    pthread_join(thread1,(void**)&state[0]);
    //pthread_join(thread2,(void**)&state[1]);

    //return (state[0] && state[1]);
    return state[0];
}

/**
 * @brief powerOffSystem
 * @return
 */
bool PWRMGMT::powerOffSystem()
{
    bool *state[2];
    state[0] = false;
    state[1] = false;
    pthread_t thread1, thread2;
    int iret1, iret2;

    args1.state = "off";
    iret1 = pthread_create(&thread1, NULL, arduino, (void*) &args1);
    if(iret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n",iret1);
        return false;
    }

    //args2.state = "off";
    //iret2 = pthread_create(&thread2, NULL, arduino, (void*) &args2);
    //if(iret2) {
    //    fprintf(stderr, "Error - pthread_create() return code: %d\n",iret2);
    //    return false;
    //}

    pthread_join(thread1,(void**)&state[0]);
    //pthread_join(thread2,(void**)&state[1]);

    //return (state[0] && state[1]);
    return state[0];
}

/**
 * @brief PWRMGMT::powerOnDS
 * @param IP
 * @param pin
 * @return
 */
bool PWRMGMT::powerOnDS(QString IP, QString pin)
{
    QString power;
    power = GetStdoutFromCommand("curl -s http://" + IP + "?" + pin + "-on");
    if (!power.contains(pin + " on"))
        return false;
    return true;
}

/**
 * @brief PWRMGMT::powerOffDS
 * @param IP
 * @param pin
 * @return
 */
bool PWRMGMT::powerOffDS(QString IP, QString pin)
{
    QString power;
    power = GetStdoutFromCommand("curl -s http://" + IP + "?" + pin + "-off");
    if (!power.contains(pin + " off"))
        return false;
    return true;
}

/**
 * @brief GetStdoutFromCommand
 * @param cmd
 * @return
 */
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

/**
 * @brief arduinoONE
 * @param ptr
 * @return
 */
void *arduino(void *ptr)
{
    arg_struct *args = (arg_struct *) ptr;
    QString power;

    power = GetStdoutFromCommand("curl -s http://" + args->pwrIP + "/?" + args->pwrArray[0][2] + "-" +args->state);

    if (!power.contains("Toggling"))
    {
        qDebug() << "Cannot connect to Arduino with IP address " << args->pwrIP << "\n";
        pthread_exit((void*)false);
    }

    for (int i = args->start + 1; i < args->end; i++)
    {
        //if (args->safety->isSafe(args->pwrArray[i][0]))
        {
            if (args->state == "on")
            {
                //if (!args->safety->isDisabled(args->pwrArray[i][0]))
                {
                    power = "curl -s http://" + args->pwrIP + "/?" + args->pwrArray[i][2] + "-on";
                    args->pwrArray[i][1] = "Green";
                }
            }
            else
            {
                power = "curl -s http://" + args->pwrIP + "/?" + args->pwrArray[i][2] + "-off";
                if (!args->safety->isDisabled(args->pwrArray[i][0]))
                        args->pwrArray[i][1] = "Black";
            }
        }
        GetStdoutFromCommand(power);
    }
    pthread_exit((void*)true);
}
