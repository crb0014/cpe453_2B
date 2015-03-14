#include <QString>
#include <QtTest>
#include "../iniops.h"
#include "../safetysys.h"
#include "../pwrmgmt.h"
#include "../sqlsys.h"
#include "../integration.h"

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

class UnitTestTest : public QObject
{
    Q_OBJECT
    INIOps * ops;
    SafetySys * safety;
    Integration * translate;
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

    // Integration Tests
    void testTranslateExistingDS();
    void testTranslateNonExistingDS();

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
    translate = new Integration();

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
//    QVERIFY2(safety->isYellow("ds1_1_4") == true,"Error Occured, Did not Detect the Detection Section that is Yellow.");
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
//    QVERIFY2(safety->isRed("ds1_1_3") == true,"Error Occured, Did not Detect the Detection Section that is Red.");
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
//    QVERIFY2(safety->isDisabled("ds1_1_2") == true,"Error Occured, Did not Detect the Detection Section that is disabled.");
}

/**
 * @brief UnitTestTest::testIsNotSafe
 */
void UnitTestTest::testIsNotSafe()
{
//    QVERIFY2(safety->isSafe("ds1_1_4") == false,"Error occured, unsafe section check returned that it was safe falsly.");
//    QVERIFY2(safety->isSafe("ds1_1_3") == false,"Error occured, unsafe section check returned that it was safe falsly.");
}

/**
 * @brief UnitTestTest::testIsSafe
 */
void UnitTestTest::testIsSafe()
{
//    QVERIFY2(safety->isSafe("ds1_1_2") == true,"Error Occured, Did not Detect the Detection Section that is safe.");
}

void UnitTestTest::testTranslateExistingDS()
{
    QVERIFY2(translate->translate("ds1_1_1") == "bob,bob2,bob3","Error Occured, integration class did not return correct translation.");
}

void UnitTestTest::testTranslateNonExistingDS()
{
    QVERIFY2(translate->translate("Error") == "None","Error Occured, integration class returned data for non existant ds.");
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
    holder << "ds1_1_1" << "0" << "black" << "\n"
           << "ds1_1_2" << "0" << "black" << "\n"
           << "ds1_1_3" << "0" << "black" << "\n"
           << "ds1_1_4" << "0" << "black" << "\n"
           << "ds1_1_5" << "0" << "black" << "\n"
           << "ds1_1_6" << "0" << "black" << "\n"
           << "ds1_1_7" << "0" << "black" << "\n"
           << "ds1_1_8" << "0" << "black" << "\n"
           << "ds1_1_9" << "0" << "black" << "\n"
           << "ds1_1_10" << "0" << "black" << "\n"
           << "ds1_1_11" << "0" << "black" << "\n"
           << "ds1_1_12" << "0" << "black" << "\n"
           << "ds1_1_13" << "0" << "black" << "\n"
           << "ds1_1_14" << "0" << "black" << "\n"
           << "ds1_1_15" << "0" << "black" << "\n"
           << "ds1_1_16" << "0" << "black" << "\n"
           << "ds1_2_1" << "0" << "black" << "\n"
           << "ds1_2_2" << "0" << "black" << "\n"
           << "ds1_2_3" << "0" << "black" << "\n"
           << "ds1_2_4" << "0" << "black" << "\n"
           << "ds1_2_5" << "0" << "black" << "\n"
           << "ds1_2_6" << "0" << "black" << "\n"
           << "ds1_2_7" << "0" << "black" << "\n"
           << "ds1_2_8" << "0" << "black" << "\n"
           << "ds1_2_9" << "0" << "black" << "\n"
           << "ds1_2_10" << "0" << "black" << "\n"
           << "ds1_2_11" << "0" << "black" << "\n"
           << "ds1_2_12" << "0" << "black" << "\n"
           << "ds1_2_13" << "0" << "black" << "\n"
           << "ds1_2_14" << "0" << "black" << "\n"
           << "ds1_2_15" << "0" << "black" << "\n"
           << "ds1_2_16" << "0" << "black" << "\n"
           << "ds1_3_1" << "0" << "black" << "\n"
           << "ds1_3_2" << "0" << "black" << "\n"
           << "ds1_3_3" << "0" << "black" << "\n"
           << "ds1_3_4" << "0" << "black" << "\n"
           << "ds1_3_5" << "0" << "black" << "\n"
           << "ds1_3_6" << "0" << "black" << "\n"
           << "ds1_3_7" << "0" << "black" << "\n"
           << "ds1_3_8" << "0" << "black" << "\n"
           << "ds1_3_9" << "0" << "black" << "\n"
           << "ds1_3_10" << "0" << "black" << "\n"
           << "ds1_3_11" << "0" << "black" << "\n"
           << "ds1_3_12" << "0" << "black" << "\n"
           << "ds1_3_13" << "0" << "black" << "\n"
           << "ds1_3_14" << "0" << "black" << "\n"
           << "ds1_3_15" << "0" << "black" << "\n"
           << "ds1_3_16" << "0" << "black" << "\n"
           << "ds1_4_1" << "0" << "black" << "\n"
           << "ds1_4_2" << "0" << "black" << "\n"
           << "ds1_4_3" << "0" << "black" << "\n"
           << "ds1_4_4" << "0" << "black" << "\n"
           << "ds1_4_5" << "0" << "black" << "\n"
           << "ds1_4_6" << "0" << "black" << "\n"
           << "ds1_4_7" << "0" << "black" << "\n"
           << "ds1_4_8" << "0" << "black" << "\n"
           << "ds1_4_9" << "0" << "black" << "\n"
           << "ds1_4_10" << "0" << "black" << "\n"
           << "ds1_4_11" << "0" << "black" << "\n"
           << "ds1_4_12" << "0" << "black" << "\n"
           << "ds1_4_13" << "0" << "black" << "\n"
           << "ds1_4_14" << "0" << "black" << "\n"
           << "ds1_4_15" << "0" << "black" << "\n"
           << "ds1_4_16" << "0" << "black" << "\n"
           << "ds2_1_1" << "0" << "black" << "\n"
           << "ds2_1_2" << "0" << "black" << "\n"
           << "ds2_1_3" << "0" << "black" << "\n"
           << "ds2_1_4" << "0" << "black" << "\n"
           << "ds2_1_5" << "0" << "black" << "\n"
           << "ds2_1_6" << "0" << "black" << "\n"
           << "ds2_1_7" << "0" << "black" << "\n"
           << "ds2_1_8" << "0" << "black" << "\n"
           << "ds2_1_9" << "0" << "black" << "\n"
           << "ds2_1_10" << "0" << "black" << "\n"
           << "ds2_1_11" << "0" << "black" << "\n"
           << "ds2_1_12" << "0" << "black" << "\n"
           << "ds2_1_13" << "0" << "black" << "\n"
           << "ds2_1_14" << "0" << "black" << "\n"
           << "ds2_1_15" << "0" << "black" << "\n"
           << "ds2_1_16" << "0" << "black" << "\n"
           << "ds2_2_1" << "0" << "black" << "\n"
           << "ds2_2_2" << "0" << "black" << "\n"
           << "ds2_2_3" << "0" << "black" << "\n"
           << "ds2_2_4" << "0" << "black" << "\n"
           << "ds2_2_5" << "0" << "black" << "\n"
           << "ds2_2_6" << "0" << "black" << "\n"
           << "ds2_2_7" << "0" << "black" << "\n"
           << "ds2_2_8" << "0" << "black" << "\n"
           << "ds2_2_9" << "0" << "black" << "\n"
           << "ds2_2_10" << "0" << "black" << "\n"
           << "ds2_2_11" << "0" << "black" << "\n"
           << "ds2_2_12" << "0" << "black" << "\n"
           << "ds2_2_13" << "0" << "black" << "\n"
           << "ds2_2_14" << "0" << "black" << "\n"
           << "ds2_2_15" << "0" << "black" << "\n"
           << "ds2_2_16" << "0" << "black" << "\n"
           << "ds2_3_1" << "0" << "black" << "\n"
           << "ds2_3_2" << "0" << "black" << "\n"
           << "ds2_3_3" << "0" << "black" << "\n"
           << "ds2_3_4" << "0" << "black" << "\n"
           << "ds2_3_5" << "0" << "black" << "\n"
           << "ds2_3_6" << "0" << "black" << "\n"
           << "ds2_3_7" << "0" << "black" << "\n"
           << "ds2_3_8" << "0" << "black" << "\n"
           << "ds2_3_9" << "0" << "black" << "\n"
           << "ds2_3_10" << "0" << "black" << "\n"
           << "ds2_3_11" << "0" << "black" << "\n"
           << "ds2_3_12" << "0" << "black" << "\n"
           << "ds2_3_13" << "0" << "black" << "\n"
           << "ds2_3_14" << "0" << "black" << "\n"
           << "ds2_3_15" << "0" << "black" << "\n"
           << "ds2_3_16" << "0" << "black" << "\n"
           << "ds2_4_1" << "0" << "black" << "\n"
           << "ds2_4_2" << "0" << "black" << "\n"
           << "ds2_4_3" << "0" << "black" << "\n"
           << "ds2_4_4" << "0" << "black" << "\n"
           << "ds2_4_5" << "0" << "black" << "\n"
           << "ds2_4_6" << "0" << "black" << "\n"
           << "ds2_4_7" << "0" << "black" << "\n"
           << "ds2_4_8" << "0" << "black" << "\n"
           << "ds2_4_9" << "0" << "black" << "\n"
           << "ds2_4_10" << "0" << "black" << "\n"
           << "ds2_4_11" << "0" << "black" << "\n"
           << "ds2_4_12" << "0" << "black" << "\n"
           << "ds2_4_13" << "0" << "black" << "\n"
           << "ds2_4_14" << "0" << "black" << "\n"
           << "ds2_4_15" << "0" << "black" << "\n"
           << "ds2_4_16" << "0" << "black" << "\n";

    QVERIFY2(sql->getTable() == holder,"Error Occured, getTable did not return the expected result.");
}

/**
 * @brief testGetColor
 */
void UnitTestTest::testGetColor()
{
    QVERIFY2(sql->getColor("ds1_1_1") == "black","Error Occured, getColor did not return the expected result.");
}

/**
 * @brief testGetStatus
 */
void UnitTestTest::testGetStatus()
{
    QVERIFY2(sql->getStatus("ds1_1_1") == false,"Error thrown when setting color");
}

/**
 * @brief testGetStatus
 */
void UnitTestTest::testSetColor()
{
    QVERIFY2(sql->setColor("ds1_1_1","green") == true,"Error thrown when setting color");
    QVERIFY2(sql->getColor("ds1_1_1") == "green","Error Occured, setColor did not return the expected result.");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true,"Error thrown when setting color");
    QVERIFY2(sql->getColor("ds1_1_1") == "black","Error Occured, setColor did not return the expected result.");
}

/**
 * @brief UnitTestTest::testSetStatus
 */
void UnitTestTest::testSetStatus()
{
    QVERIFY2(sql->setStatus("ds1_1_1",true) == true,"Error thrown when setting status");
    QVERIFY2(sql->getStatus("ds1_1_1") == true,"Error Occured, setStatus did not return the expected result.");
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true,"Error thrown when setting status");
    QVERIFY2(sql->getStatus("ds1_1_1") == false,"Error Occured, setStatus did not return the expected result.");
}

/**
 * @brief testPowerOnSystem
 */
void UnitTestTest::testPowerOnSystem()
{
    QVERIFY2(pwr->powerOnSystem() == true,"Error Occured, Did not Correctly Power on System.");
    QVERIFY2(sql->getStatus("ds1_1_1") == true, "Error Occured, did not detect the correct status");
}

/**
 * @brief testPowerOffSystem
 */
void UnitTestTest::testPowerOffSystem()
{
    QVERIFY2(pwr->powerOffSystem() == true,"Error Occured, Did not Correctly Power off System.");
    QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnDSPass
 */
void UnitTestTest::testPowerOnDSPass()
{
    QVERIFY2(pwr->powerOnDS(ip1,"54","ds1_1_1") == true,"Error Occured, Did not Correctly Power on detection section.");
    QVERIFY2(sql->getStatus("ds1_1_1") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "green", "Error Occured, did not detect the correct color");
    QVERIFY2(pwr->powerOffDS(ip1,"54","ds1_1_1") == true,"Error Occured, Did not Correctly Power on detection section.");
    QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "gray", "Error Occured, did not detect the correct color");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnRedDs
 */
void UnitTestTest::testPowerOnRedDs()
{
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","red") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOnDS(ip1,"false","ds1_1_1") == false,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "red", "Error Occured, did not detect the correct color");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnYellowDs
 */
void UnitTestTest::testPowerOnYellowDs()
{
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","yellow") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOnDS(ip1,"false","ds1_1_1") == false,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "yellow", "Error Occured, did not detect the correct color");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOnGrayDs
 */
void UnitTestTest::testPowerOnGrayDs()
{
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","gray") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOnDS(ip1,"54","ds1_1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getStatus("ds1_1_1") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "green", "Error Occured, did not detect the correct color");
    QVERIFY2(pwr->powerOffDS(ip1,"54","ds1_1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    QVERIFY2(sql->getColor("ds1_1_1") == "gray", "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOffRedDs
 */
void UnitTestTest::testPowerOffRedDs()
{
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","red") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOffDS(ip1,"54","ds1_1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    //qDebug() << "\n\n\ncolor: " << sql->getColor("ds1_1_1") << endl;
    //QVERIFY2(sql->getColor("ds1_1_1") == "red", "Error Occured, did not detect the correct status");
    //QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOffYellowDs
 */
void UnitTestTest::testPowerOffYellowDs()
{
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","yellow") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOffDS(ip1,"54","ds1_1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    //qDebug() << "\n\n\ncolor: " << sql->getColor("ds1_1_1") << endl;
    //QVERIFY2(sql->getColor("ds1_1_1") == "yellow", "Error Occured, did not detect the correct status");
    //QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

/**
 * @brief UnitTestTest::testPowerOffGrayDs
 */
void UnitTestTest::testPowerOffGrayDs()
{
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","gray") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(pwr->powerOffDS(ip1,"54","ds1_1_1") == true,"Error Occured, Powered on a section that doesn't exist.");
    //qDebug() << "\n\n\ncolor: " << sql->getColor("ds1_1_1") << endl;
    //QVERIFY2(sql->getColor("ds1_1_1") == "gray", "Error Occured, did not detect the correct status");
    //QVERIFY2(sql->getStatus("ds1_1_1") == false, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->setColor("ds1_1_1","black") == true, "Error Occured, did not detect the correct status");
    QVERIFY2(sql->getColor("ds1_1_1") == "black", "Error Occured, did not detect the correct status");
}

QTEST_APPLESS_MAIN(UnitTestTest)

#include "tst_unittesttest.moc"
