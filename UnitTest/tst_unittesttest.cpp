#include <QString>
#include <QtTest>
#include "../iniops.h"
#include "../safetysys.h"
#include "../config.h"

class UnitTestTest : public QObject
{
    Q_OBJECT
    INIOps * ops;
    SafetySys * safety;

public:
    UnitTestTest();

private Q_SLOTS:
    void testGetIPConfigFileNotFound();
    void testGetIPArduino1();
    void testGetIPArduino2();
    void testWriteINI();
    void testIsYellowFalse();
    void testIsYellowTrue();
    void testIsRedFalse();
    void testIsRedTrue();
    void testIsDisabledTrue();
    void testIsDisabledFalse();
    void testIsSafe();
    void testIsNotSafe();
};

/**
 * @brief UnitTestTest::UnitTestTest
 */
UnitTestTest::UnitTestTest() {}


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
    ops = new INIOps("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QString knownIP = "1.1.1.1";
    QVERIFY2(knownIP == ops->getIPArduino1(), "Arduino 1 IP Address did not match.");
}

/**
 * @brief UnitTestTest::testGetIPArduino2
 */
void UnitTestTest::testGetIPArduino2()
{
    ops = new INIOps("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QString knownIP = "2.2.2.2";
    QVERIFY2(knownIP == ops->getIPArduino2(), "Arduino 2 IP Address did not match.");
}

/**
 * @brief UnitTestTest::testWriteINI
 */
void UnitTestTest::testWriteINI()
{
    ops = new INIOps("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QString ip1 = "1.1.1.1";
    QString ip2 = "2.2.2.2";
    QString array[128][3] = {
        {"ds1_1_1","Black","54"},
        {"ds1_1_2","Gray","55"},
        {"ds1_1_3","Red","56"},
        {"ds1_1_4","Yellow","57"},
        {"ds1_1_5","Green","58"}
    };
    QVERIFY2(ops->writeINI(ip1,ip2,array) == false, "Error Occured while writing to ini.");
}

/**
 * @brief UnitTestTest::testIsYellowFalse
 */
void UnitTestTest::testIsYellowFalse()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isYellow("bob") == false,"Error Occured, Detected a yellow section that does not exist");
}

/**
 * @brief UnitTestTest::testIsYellowTrue
 */
void UnitTestTest::testIsYellowTrue()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isYellow("ds1_1_4") == true,"Error Occured, Did not Detect the Detection Section that is Yellow.");
}

/**
 * @brief UnitTestTest::testIsRedFalse
 */
void UnitTestTest::testIsRedFalse()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isRed("bob") == false,"Error Occured, Detected a red section that does not exist");
}

/**
 * @brief UnitTestTest::testIsRedTrue
 */
void UnitTestTest::testIsRedTrue()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isRed("ds1_1_3") == true,"Error Occured, Did not Detect the Detection Section that is Red.");
}

/**
 * @brief UnitTestTest::testIsDisabledFalse
 */
void UnitTestTest::testIsDisabledFalse()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isDisabled("bob") == false,"Error Occured, Detected a disabled section that does not exist");
}

/**
 * @brief UnitTestTest::testIsDisabledTrue
 */
void UnitTestTest::testIsDisabledTrue()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isDisabled("ds1_1_2") == true,"Error Occured, Did not Detect the Detection Section that is disabled.");
}

/**
 * @brief UnitTestTest::testIsNotSafe
 */
void UnitTestTest::testIsNotSafe()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isSafe("ds1_1_3") == false,"Error occured, unsafe section check returned that it was safe falsly.");
    QVERIFY2(safety->isSafe("ds1_1_4") == false,"Error occured, unsafe section check returned that it was safe falsly.");
}

/**
 * @brief UnitTestTest::testIsSafe
 */
void UnitTestTest::testIsSafe()
{
    safety = new SafetySys("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QVERIFY2(safety->isSafe("ds1_1_2") == true,"Error Occured, Did not Detect the Detection Section that is safe.");
}

QTEST_APPLESS_MAIN(UnitTestTest)

#include "tst_unittesttest.moc"
