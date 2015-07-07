#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T19:49:51
#
#-------------------------------------------------

QT       -= gui
QT       += core \
            testlib

CONFIG   -= app_bundle
CONFIG   += console \
            testcase

TEMPLATE = app

SOURCES += \
    ModelTest.cpp \
    Main.cpp \
    QTxToolboxLibTests.cpp

HEADERS += \
    ModelTest.h \
    QTxToolboxLibTests.h

INCLUDEPATH += $$PWD/../QtxToolboxLib

TARGET      = QtxToolboxTest
