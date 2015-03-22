#include <QString>
#include <QtTest>
#include "../iniops.h"
#include "../safetysys.h"
#include "../pwrmgmt.h"
#include "../sqlsys.h"

// Casey School
//#define TEST_CONFIG_FILE "..."
// Casey Home
#define TEST_CONFIG_FILE "/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini"
#define TEST_DB_FILE "/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/unitTest.db"
// Chumzy Home
//#define TEST_CONFIG_FILE "..."
//Chumzy Home
//#define TEST_CONFIG_FILE "..."
// Chumzy School
//#define TEST_CONFIG_FILE "..."
// Jay School
//#define TEST_CONFIG_FILE "..."
// Jay Home
//#define TEST_CONFIG_FILE "..."

static QString array[I][J] = {
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

class UnitTestTest : public QObject
{
    Q_OBJECT
    INIOps * ops;
    SafetySys * safety;
    PWRMGMT * pwr;
    SQLSys * sql;
    QString ip1;
    QString ip2;

public:
    UnitTestTest();

private Q_SLOTS:

    // INIOps Tests
    void testGetIPConfigFileNotFound();
    void testGetIPArduino1();
    void testGetIPArduino2();
    void testWriteINI();

    // SafetySys Tests
    void testIsYellowFalse();
    void testIsYellowTrue();
    void testIsRedFalse();
    void testIsRedTrue();
    void testIsDisabledTrue();
    void testIsDisabledFalse();
    void testIsSafe();
    void testIsNotSafe();

    // SQLSys Tests
    void testIsConnected();
    void testPrintDB();
    void testGetColor();
    void testGetStatus();
    void testSetColor();
    void testSetStatus();

    // PWRMGMT Tests
    void testPowerOnSystem();
    void testPowerOffSystem();
    void testPowerOnDSPass();
    void testPowerOnRedDs();
    void testPowerOnYellowDs();
    void testPowerOnGrayDs();
    void testPowerOffRedDs();
    void testPowerOffYellowDs();
    void testPowerOffGrayDs();

};

/**
 * @brief UnitTestTest::UnitTestTest
 */
UnitTestTest::UnitTestTest()
{
    safety = new SafetySys();
    sql = new SQLSys("QSQLITE",TEST_DB_FILE);

    pwr = new PWRMGMT(sql,array);
    ip1 = "192.168.137.2";
    ip2 = "192.168.137.3";
}


/**
 * @brief UnitTestTest::testCase1
 */
void UnitTestTest::testGetIPConfigFileNotFound()
{
    ops = new INIOps("nonExistantFile.ini");
    QVERIFY2("Error Occured Opening INI" == ops->getIPArduino1(), "Found ini that doesn't exist.");
}

/**
 * @brief UnitTestTest::testGetIPArduino1Pass
 */
void UnitTestTest::testGetIPArduino1()
{
    ops = new INIOps(TEST_CONFIG_FILE);
    QString knownIP = "192.168.137.2";
    QVERIFY2(knownIP == ops->getIPArduino1(), "Arduino 1 IP Address did not match.");
}

/**
 * @brief UnitTestTest::testGetIPArduino2
 */
void UnitTestTest::testGetIPArduino2()
{
    ops = new INIOps(TEST_CONFIG_FILE);
    QString knownIP = "192.168.137.3";
    QVERIFY2(knownIP == ops->getIPArduino2(), "Arduino 2 IP Address did not match.");
}

/**
 * @brief UnitTestTest::testWriteINI
 */
void UnitTestTest::testWriteINI()
{
    ops = new INIOps(TEST_CONFIG_FILE);
    QString ip1 = "192.168.137.2";
    QString ip2 = "192.168.137.3";
    QVERIFY2(ops->writeINI(ip1,ip2,array) == false, "Error Occured while writing to ini.");
}

/**
 * @brief UnitTestTest::testIsYellowFalse
 */
void UnitTestTest::testIsYellowFalse()
{
//    QVERIFY2(safety->isYellow("bob") == false,"Error Occured, Detected a yellow section that does not exist");
}

/**
 * @brief UnitTestTest::testIsYellowTrue
 */
void UnitTestTest::testIsYellowTrue()
{
//    QVERIFY2(safety->isYellow("1_4") == true,"Error Occured, Did not Detect the Detection Section that is Yellow.");
}

/**
 * @brief UnitTestTest::testIsRedFalse
 */
void UnitTestTest::testIsRedFalse()
{
//    QVERIFY2(safety->isRed("bob") == false,"Error Occured, Detected a red section that does not exist");
}

/**
 * @brief UnitTestTest::testIsRedTrue
 */
void UnitTestTest::testIsRedTrue()
{
//    QVERIFY2(safety->isRed("1_3") == true,"Error Occured, Did not Detect the Detection Section that is Red.");
}

/**
 * @brief UnitTestTest::testIsDisabledFalse
 */
void UnitTestTest::testIsDisabledFalse()
{
//    QVERIFY2(safety->isDisabled("bob") == false,"Error Occured, Detected a disabled section that does not exist");
}

/**
 * @brief UnitTestTest::testIsDisabledTrue
 */
void UnitTestTest::testIsDisabledTrue()
{
//    QVERIFY2(safety->isDisabled("1_2") == true,"Error Occured, Did not Detect the Detection Section that is disabled.");
}

/**
 * @brief UnitTestTest::testIsNotSafe
 */
void UnitTestTest::testIsNotSafe()
{
//    QVERIFY2(safety->isSafe("1_4") == false,"Error occured, unsafe section check returned that it was safe falsly.");
//    QVERIFY2(safety->isSafe("1_3") == false,"Error occured, unsafe section check returned that it was safe falsly.");
}

/**
 * @brief UnitTestTest::testIsSafe
 */
void UnitTestTest::testIsSafe()
{
//    QVERIFY2(safety->isSafe("1_2") == true,"Error Occured, Did not Detect the Detection Section that is safe.");
}

/**
 * @brief testIsConnected
 */
void UnitTestTest::testIsConnected()
{
    QVERIFY2(sql->isConnected() == true,"Error Occured, Not connected to Database");
}

void UnitTestTest::testPrintDB()
{
    QStringList holder;
    holder << "1_1" << "0" << "black" << "\n"
           << "1_2" << "0" << "black" << "\n"
           << "1_3" << "0" << "black" << "\n"
           << "1_4" << "0" << "black" << "\n"
           << "1_5" << "0" << "black" << "\n"
           << "1_6" << "0" << "black" << "\n"
           << "1_7" << "0" << "black" << "\n"
           << "1_8" << "0" << "black" << "\n"
           << "1_9" << "0" << "black" << "\n"
           << "1_10" << "0" << "black" << "\n"
           << "1_11" << "0" << "black" << "\n"
           << "1_12" << "0" << "black" << "\n"
           << "1_13" << "0" << "black" << "\n"
           << "1_14" << "0" << "black" << "\n"
           << "1_15" << "0" << "black" << "\n"
           << "1_16" << "0" << "black" << "\n"
           << "2_1" << "0" << "black" << "\n"
           << "2_2" << "0" << "black" << "\n"
           << "2_3" << "0" << "black" << "\n"
           << "2_4" << "0" << "black" << "\n"
           << "2_5" << "0" << "black" << "\n"
           << "2_6" << "0" << "black" << "\n"
           << "2_7" << "0" << "black" << "\n"
           << "2_8" << "0" << "black" << "\n"
           << "2_9" << "0" << "black" << "\n"
           << "2_10" << "0" << "black" << "\n"
           << "2_11" << "0" << "black" << "\n"
           << "2_12" << "0" << "black" << "\n"
           << "2_13" << "0" << "black" << "\n"
           << "2_14" << "0" << "black" << "\n"
           << "2_15" << "0" << "black" << "\n"
           << "2_16" << "0" << "black" << "\n"
           << "3_1" << "0" << "black" << "\n"
           << "3_2" << "0" << "black" << "\n"
           << "3_3" << "0" << "black" << "\n"
           << "3_4" << "0" << "black" << "\n"
           << "3_5" << "0" << "black" << "\n"
           << "3_6" << "0" << "black" << "\n"
           << "3_7" << "0" << "black" << "\n"
           << "3_8" << "0" << "black" << "\n"
           << "3_9" << "0" << "black" << "\n"
           << "3_10" << "0" << "black" << "\n"
           << "3_11" << "0" << "black" << "\n"
           << "3_12" << "0" << "black" << "\n"
           << "3_13" << "0" << "black" << "\n"
           << "3_14" << "0" << "black" << "\n"
           << "3_15" << "0" << "black" << "\n"
           << "3_16" << "0" << "black" << "\n"
           << "4_1" << "0" << "black" << "\n"
           << "4_2" << "0" << "black" << "\n"
           << "4_3" << "0" << "black" << "\n"
           << "4_4" << "0" << "black" << "\n"
           << "4_5" << "0" << "black" << "\n"
           << "4_6" << "0" << "black" << "\n"
           << "4_7" << "0" << "black" << "\n"
           << "4_8" << "0" << "black" << "\n"
           << "4_9" << "0" << "black" << "\n"
           << "4_10" << "0" << "black" << "\n"
           << "4_11" << "0" << "black" << "\n"
           << "4_12" << "0" << "black" << "\n"
           << "4_13" << "0" << "black" << "\n"
           << "4_14" << "0" << "black" << "\n"
           << "4_15" << "0" << "black" << "\n"
           << "4_16" << "0" << "black" << "\n"
           << "5_1" << "0" << "black" << "\n"
           << "5_2" << "0" << "black" << "\n"
           << "5_3" << "0" << "black" << "\n"
           << "5_4" << "0" << "black" << "\n"
           << "5_5" << "0" << "black" << "\n"
           << "5_6" << "0" << "black" << "\n"
           << "5_7" << "0" << "black" << "\n"
           << "5_8" << "0" << "black" << "\n"
           << "5_9" << "0" << "black" << "\n"
           << "5_10" << "0" << "black" << "\n"
           << "5_11" << "0" << "black" << "\n"
           << "5_12" << "0" << "black" << "\n"
           << "5_13" << "0" << "black" << "\n"
           << "5_14" << "0" << "black" << "\n"
           << "5_15" << "0" << "black" << "\n"
           << "5_16" << "0" << "black" << "\n"
           << "6_1" << "0" << "black" << "\n"
           << "6_2" << "0" << "black" << "\n"
           << "6_3" << "0" << "black" << "\n"
           << "6_4" << "0" << "black" << "\n"
           << "6_5" << "0" << "black" << "\n"
           << "6_6" << "0" << "black" << "\n"
           << "6_7" << "0" << "black" << "\n"
           << "6_8" << "0" << "black" << "\n"
           << "6_9" << "0" << "black" << "\n"
           << "6_10" << "0" << "black" << "\n"
           << "6_11" << "0" << "black" << "\n"
           << "6_12" << "0" << "black" << "\n"
           << "6_13" << "0" << "black" << "\n"
           << "6_14" << "0" << "black" << "\n"
           << "6_15" << "0" << "black" << "\n"
           << "6_16" << "0" << "black" << "\n"
           << "7_1" << "0" << "black" << "\n"
           << "7_2" << "0" << "black" << "\n"
           << "7_3" << "0" << "black" << "\n"
           << "7_4" << "0" << "black" << "\n"
           << "7_5" << "0" << "black" << "\n"
           << "7_6" << "0" << "black" << "\n"
           << "7_7" << "0" << "black" << "\n"
           << "7_8" << "0" << "black" << "\n"
           << "7_9" << "0" << "black" << "\n"
           << "7_10" << "0" << "black" << "\n"
           << "7_11" << "0" << "black" << "\n"
           << "7_12" << "0" << "black" << "\n"
           << "7_13" << "0" << "black" << "\n"
           << "7_14" << "0" << "black" << "\n"
           << "7_15" << "0" << "black" << "\n"
           << "7_16" << "0" << "black" << "\n"
           << "8_1" << "0" << "black" << "\n"
           << "8_2" << "0" << "black" << "\n"
           << "8_3" << "0" << "black" << "\n"
           << "8_4" << "0" << "black" << "\n"
           << "8_5" << "0" << "black" << "\n"
           << "8_6" << "0" << "black" << "\n"
           << "8_7" << "0" << "black" << "\n"
           << "8_8" << "0" << "black" << "\n"
           << "8_9" << "0" << "black" << "\n"
           << "8_10" << "0" << "black" << "\n"
           << "8_11" << "0" << "black" << "\n"
           << "8_12" << "0" << "black" << "\n"
           << "8_13" << "0" << "black" << "\n"
           << "8_14" << "0" << "black" << "\n"
           << "8_15" << "0" << "black" << "\n"
           << "8_16" << "0" << "black" << "\n";

    QVERIFY2(sql->getTable() == holder,"Error Occured, getTable did not return the expected result.");
}

/**
 * @brief testGetColor
 */
void UnitTestTest::testGetColor()
{
    QVERIFY2(sql->getColor("1_1") == "black","Error Occured, getColor did not return the expected result.");
}

/**
 * @brief testGetStatus
 */
void UnitTestTest::testGetStatus()
{
    QVERIFY2(sql->getStatus("1_1") == false,"Error thrown when setting color");
}

/**
 * @brief testGetStatus
 */
void UnitTestTest::testSetColor()
{
    QVERIFY2(sql->setColor("1_1","green") == true,"Error thrown when setting color");
    QVERIFY2(sql->getColor("1_1") == "green","Error Occured, setColor did not return the expected result.");
    QVERIFY2(sql->setColor("1_1","black") == true,"Error thrown when setting color");
    QVERIFY2(sql->getColor("1_1") == "black","Error Occured, setColor did not return the expected result.");
}

/**
 * @brief UnitTestTest::testSetStatus
 */
void UnitTestTest::testSetStatus()
{
    QVERIFY2(sql->setStatus("1_1",true) == true,"Error thrown when setting status");
    QVERIFY2(sql->getStatus("1_1") == true,"Error Occured, setStatus did not return the expected result.");
    QVERIFY2(sql->setStatus("1_1",false) == true,"Error thrown when setting status");
    QVERIFY2(sql->getStatus("1_1") == false,"Error Occured, setStatus did not return the expected result.");
}

/**
 * @brief testPowerOnSystem
 */
void UnitTestTest::testPowerOnSystem()
{
    QVERIFY2(pwr->powerOnSystem() == true,"Error Occured, Did not Correctly Power on System.");
    QVERIFY2(sql->getStatus("1_1") == true, "Error Occured, did not detect the correct status");
}

/**
 * @brief testPowerOffSystem
 */
void UnitTestTest::testPowerOffSystem()
{
    QVERIFY2(pwr->powerOffSystem() == true,"Error Occured, Did not Correctly Power off System.");
    QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnDSPass
 */
void UnitTestTest::testPowerOnDSPass()
{
    QVERIFY2(pwr->powerOnDS(ip1,"54","1_1") == true,"Error Occured, Did not Correctly Power on detection section.");
    QVERIFY2(sql->getStatus("1_1") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "green", "Error Occured, did not detect the correct color");
    QVERIFY2(pwr->powerOffDS(ip1,"54","1_1") == true,"Error Occured, Did not Correctly Power on detection section.");
    QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "gray", "Error Occured, did not detect the correct color");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnRedDs
 */
void UnitTestTest::testPowerOnRedDs()
{
    QVERIFY2(sql->setStatus("1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","red") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOnDS(ip1,"false","1_1") == false,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "red", "Error Occured, did not detect the correct color");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnYellowDs
 */
void UnitTestTest::testPowerOnYellowDs()
{
    QVERIFY2(sql->setStatus("1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","yellow") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOnDS(ip1,"false","1_1") == false,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "yellow", "Error Occured, did not detect the correct color");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnGrayDs
 */
void UnitTestTest::testPowerOnGrayDs()
{
    QVERIFY2(sql->setStatus("1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","gray") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOnDS(ip1,"54","1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getStatus("1_1") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "green", "Error Occured, did not detect the correct color");
    QVERIFY2(pwr->powerOffDS(ip1,"54","1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getColor("1_1") == "gray", "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOffRedDs
 */
void UnitTestTest::testPowerOffRedDs()
{
    QVERIFY2(sql->setStatus("1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","red") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOffDS(ip1,"54","1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    //qDebug() << "\n\n\ncolor: " << sql->getColor("1_1") << endl;
    //QVERIFY2(sql->getColor("1_1") == "red", "Error Occured, did not detect the correct status");
    //QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOffYellowDs
 */
void UnitTestTest::testPowerOffYellowDs()
{
    QVERIFY2(sql->setStatus("1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","yellow") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOffDS(ip1,"54","1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    //qDebug() << "\n\n\ncolor: " << sql->getColor("1_1") << endl;
    //QVERIFY2(sql->getColor("1_1") == "yellow", "Error Occured, did not detect the correct status");
    //QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOffGrayDs
 */
void UnitTestTest::testPowerOffGrayDs()
{
    QVERIFY2(sql->setStatus("1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","gray") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOffDS(ip1,"54","1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    //qDebug() << "\n\n\ncolor: " << sql->getColor("1_1") << endl;
    //QVERIFY2(sql->getColor("1_1") == "gray", "Error Occured, did not detect the correct status");
    //QVERIFY2(sql->getStatus("1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("1_1") == "black", "Error Occured, did not detect the correct status");
}

QTEST_APPLESS_MAIN(UnitTestTest)

#include "tst_unittesttest.moc"
