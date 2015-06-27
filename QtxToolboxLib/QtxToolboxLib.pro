#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T19:33:58
#
#-------------------------------------------------

QT       -= gui

TARGET = QtxToolboxLib
TEMPLATE = lib

DEFINES += QTXTOOLBOXLIB_LIBRARY

SOURCES += \
    QtxToolboxLib.cpp \
    SQLite/shell.c \
    SQLite/sqlite3.c \
    DecNumber/decBasic.c \
    DecNumber/decCommon.c \
    DecNumber/decContext.c \
    DecNumber/decDouble.c \
    DecNumber/decimal32.c \
    DecNumber/decimal64.c \
    DecNumber/decimal128.c \
    DecNumber/decNumber.c \
    DecNumber/decPacked.c \
    DecNumber/decQuad.c \
    DecNumber/decSingle.c \
    QtxDec/QDecContext.cpp \
    QtxDec/QDecDouble.cpp \
    QtxDec/QDecNumber.cpp \
    QtxDec/QDecPacked.cpp \
    QtxDec/QDecQuad.cpp \
    QtxDec/QDecSingle.cpp

HEADERS += \
    QtxToolboxLib.h \
    QtxToolboxLib_global.h \
    SQLite/sqlite3.h \
    SQLite/sqlite3ext.h \
    DecNumber/decContext.h \
    DecNumber/decDouble.h \
    DecNumber/decDPD.h \
    DecNumber/decimal32.h \
    DecNumber/decimal64.h \
    DecNumber/decimal128.h \
    DecNumber/decNumber.h \
    DecNumber/decNumberLocal.h \
    DecNumber/decPacked.h \
    DecNumber/decQuad.h \
    DecNumber/decSingle.h \
    QtxDec/QDecContext.h \
    QtxDec/QDecDouble.h \
    QtxDec/QDecFwd.h \
    QtxDec/QDecNumber.h \
    QtxDec/QDecPacked.h \
    QtxDec/QDecQuad.h \
    QtxDec/QDecSingle.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES +=
