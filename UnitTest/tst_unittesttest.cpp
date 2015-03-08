#include <QString>
#include <QtTest>
#include "../iniops.h"
#include "../safetysys.h"
#include "../config.h"
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

class UnitTestTest : public QObject
{
    Q_OBJECT
    INIOps * ops;
    SafetySys * safety;
    PWRMGMT * pwr;
    SQLSys * sql;
    QString array[128][3];
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

    // PWRMGMT Tests
    void testPowerOnSystem();
    void testPowerOffSystem();
    void testPowerOnDSPass();
    void testPowerOnDSFail();
    void testPowerOffDSPass();
    void testPowerOffDSFail();

    // SQLSys Tests
    void testIsConnected();
    void testPrintDB();
    void testGetColor();
    void testGetStatus();
    void testSetColor();
    void testSetStatus();
};

/**
 * @brief UnitTestTest::UnitTestTest
 */
UnitTestTest::UnitTestTest()
{
    sql = new SQLSys("QSQLITE",TEST_DB_FILE);

    array[0][0] = "ds1_1_1";
    array[0][1] = "Black";
    array[0][2] = "54";
    array[1][0] = "ds1_1_2";
    array[1][1] = "Gray";
    array[1][2] = "55";
    array[2][0] = "ds1_1_3";
    array[2][1] = "Red";
    array[2][2] = "56";
    array[3][0] = "ds1_1_4";
    array[3][1] = "Yellow";
    array[3][2] = "57";
    array[4][0] = "ds1_1_5";
    array[4][1] = "Green";
    array[4][2] = "58";

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
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isYellow("bob") == false,"Error Occured, Detected a yellow section that does not exist");
}

/**
 * @brief UnitTestTest::testIsYellowTrue
 */
void UnitTestTest::testIsYellowTrue()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isYellow("ds1_1_4") == true,"Error Occured, Did not Detect the Detection Section that is Yellow.");
}

/**
 * @brief UnitTestTest::testIsRedFalse
 */
void UnitTestTest::testIsRedFalse()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isRed("bob") == false,"Error Occured, Detected a red section that does not exist");
}

/**
 * @brief UnitTestTest::testIsRedTrue
 */
void UnitTestTest::testIsRedTrue()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isRed("ds1_1_3") == true,"Error Occured, Did not Detect the Detection Section that is Red.");
}

/**
 * @brief UnitTestTest::testIsDisabledFalse
 */
void UnitTestTest::testIsDisabledFalse()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isDisabled("bob") == false,"Error Occured, Detected a disabled section that does not exist");
}

/**
 * @brief UnitTestTest::testIsDisabledTrue
 */
void UnitTestTest::testIsDisabledTrue()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isDisabled("ds1_1_2") == true,"Error Occured, Did not Detect the Detection Section that is disabled.");
}

/**
 * @brief UnitTestTest::testIsNotSafe
 */
void UnitTestTest::testIsNotSafe()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isSafe("ds1_1_4") == false,"Error occured, unsafe section check returned that it was safe falsly.");
    QVERIFY2(safety->isSafe("ds1_1_3") == false,"Error occured, unsafe section check returned that it was safe falsly.");
}

/**
 * @brief UnitTestTest::testIsSafe
 */
void UnitTestTest::testIsSafe()
{
    safety = new SafetySys(TEST_CONFIG_FILE);
    QVERIFY2(safety->isSafe("ds1_1_2") == true,"Error Occured, Did not Detect the Detection Section that is safe.");
}

/**
 * @brief testPowerOnSystem
 */
void UnitTestTest::testPowerOnSystem()
{
    pwr = new PWRMGMT(dsArray,TEST_CONFIG_FILE);
    QVERIFY2(pwr->powerOnSystem() == true,"Error Occured, Did not Correctly Power on System.");
}

/**
 * @brief testPowerOffSystem
 */
void UnitTestTest::testPowerOffSystem()
{
    pwr = new PWRMGMT(dsArray,TEST_CONFIG_FILE);
    QVERIFY2(pwr->powerOffSystem() == true,"Error Occured, Did not Correctly Power off System.");
}

/**
 * @brief testPowerOnDSPass
 * @param ds
 */
void UnitTestTest::testPowerOnDSPass()
{
    pwr = new PWRMGMT(dsArray,TEST_CONFIG_FILE);
    QVERIFY2(pwr->powerOnDS(ip1,"1") == true,"Error Occured, Did not Correctly Power on detection section.");
}

/**
 * @brief testPowerOnDSFail
 * @param ds
 */
void UnitTestTest::testPowerOnDSFail()
{
    pwr = new PWRMGMT(dsArray,TEST_CONFIG_FILE);
    QVERIFY2(pwr->powerOnDS(ip1,"false") == false,"Error Occured, Powered on a section that doesn't exist.");
}

/**
 * @brief testPowerOffDSPass
 * @param ds
 */
void UnitTestTest::testPowerOffDSPass()
{
    pwr = new PWRMGMT(dsArray,TEST_CONFIG_FILE);
    QVERIFY2(pwr->powerOffDS(ip1,"1") == true,"Error Occured, Did not Correctly Power off detection section.");
}

/**
 * @brief testPowerOffDSFail
 * @param ds
 */
void UnitTestTest::testPowerOffDSFail()
{
    pwr = new PWRMGMT(dsArray,TEST_CONFIG_FILE);
    QVERIFY2(pwr->powerOffDS(ip1,"false") == false,"Error Occured, Powered off a section that doesn't exist.");
}

/**
 * @brief testPrintTable
 */
void UnitTestTest::testIsConnected()
{
    QVERIFY2(sql->isConnected() == true,"Error Occured, Not connected to Database");
}

void UnitTestTest::testPrintDB()
{
    QStringList holder;
    holder << "ds1_1_1" << "FALSE" << "black" << "\n"
           << "ds1_1_2" << "FALSE" << "black" << "\n"
           << "ds1_1_3" << "FALSE" << "black" << "\n"
           << "ds1_1_4" << "FALSE" << "black" << "\n"
           << "ds1_1_5" << "FALSE" << "black" << "\n"
           << "ds1_1_6" << "FALSE" << "black" << "\n"
           << "ds1_1_7" << "FALSE" << "black" << "\n"
           << "ds1_1_8" << "FALSE" << "black" << "\n"
           << "ds1_1_9" << "FALSE" << "black" << "\n"
           << "ds1_1_10" << "FALSE" << "black" << "\n"
           << "ds1_1_11" << "FALSE" << "black" << "\n"
           << "ds1_1_12" << "FALSE" << "black" << "\n"
           << "ds1_1_13" << "FALSE" << "black" << "\n"
           << "ds1_1_14" << "FALSE" << "black" << "\n"
           << "ds1_1_15" << "FALSE" << "black" << "\n"
           << "ds1_1_16" << "FALSE" << "black" << "\n";

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
    QVERIFY2(sql->setStatus("ds1_1_1",true) == true,"Error thrown when setting color");
    QVERIFY2(sql->getStatus("ds1_1_1") == true,"Error Occured, setColor did not return the expected result.");
    QVERIFY2(sql->setStatus("ds1_1_1",false) == true,"Error thrown when setting color");
    QVERIFY2(sql->getStatus("ds1_1_1") == false,"Error Occured, setColor did not return the expected result.");
}

QTEST_APPLESS_MAIN(UnitTestTest)

#include "tst_unittesttest.moc"
