#include <QString>
#include <QtTest>
#include "../iniops.h"
#include "../config.h"

class UnitTestTest : public QObject
{
    Q_OBJECT
    INIOps * ops;

public:
    UnitTestTest();

private Q_SLOTS:
    void testGetIPConfigFileNotFound();
    void testGetIPArduino1();
    void testGetIPArduino2();
    void testWriteINI();
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

void UnitTestTest::testGetIPArduino2()
{
    ops = new INIOps("/home/cboydston/Desktop/cpe453/pwrMGMTSystemUI/pwrMGMTSystemUI/UnitTest/testConfig.ini");
    QString knownIP = "2.2.2.2";
    QVERIFY2(knownIP == ops->getIPArduino2(), "Arduino 2 IP Address did not match.");
}

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

QTEST_APPLESS_MAIN(UnitTestTest)

#include "tst_unittesttest.moc"
