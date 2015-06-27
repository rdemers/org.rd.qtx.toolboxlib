#include "ModelTest.h"

#include <QtTest>

ModelTest::ModelTest(QObject *parent) : QObject(parent)
{
}

void ModelTest::FirstTest()
{
    // Test
    QVERIFY2(0 == 0, "Expect to be zero.");
}
