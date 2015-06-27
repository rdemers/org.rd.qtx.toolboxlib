#include <QtTest/QTest>
#include "ModelTest.h"

QTEST_APPLESS_MAIN(ModelTest)

// QTEST_MAIN         – Implements a main() function that instantiates a QApplication object
//                      and the Test Class, then executes all tests in the order they were defined.
// QTEST_GUILESS_MAIN – The same as QTEST_MAIN but instead of instantiating a QApplication object
//                      it instantiates a QCoreApplication object.
// QTEST_APPLESS_MAIN – The same as QTEST_MAIN but does not instantiates a QApplication object, just
//                      the Test Class.
