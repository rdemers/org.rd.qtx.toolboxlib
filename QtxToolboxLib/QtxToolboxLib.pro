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
    Udt4/api.cpp \
    Udt4/buffer.cpp \
    Udt4/cache.cpp \
    Udt4/ccc.cpp \
    Udt4/channel.cpp \
    Udt4/common.cpp \
    Udt4/core.cpp \
    Udt4/epoll.cpp \
    Udt4/list.cpp \
    Udt4/md5.cpp \
    Udt4/packet.cpp \
    Udt4/queue.cpp \
    Udt4/window.cpp \
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
    Udt4/api.h \
    Udt4/buffer.h \
    Udt4/cache.h \
    Udt4/ccc.h \
    Udt4/channel.h \
    Udt4/common.h \
    Udt4/core.h \
    Udt4/epoll.h \
    Udt4/list.h \
    Udt4/md5.h \
    Udt4/packet.h \
    Udt4/queue.h \
    Udt4/udt.h \
    Udt4/window.h \
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
