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
    Main.cpp

HEADERS += \
    ModelTest.h

INCLUDEPATH += $$PWD/../QtxToolboxLib

TARGET      = QtxToolboxTest
