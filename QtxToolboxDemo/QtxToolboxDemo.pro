#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T07:23:08
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui

TEMPLATE = app

SOURCES +=  \
    Main.cpp \
    MainWindow.cpp

HEADERS  += \
    MainWindow.h

FORMS += \
    MainWindow.ui

INCLUDEPATH += $$PWD/../QtxToolboxLib

TARGET   = QtxToolboxDemo
