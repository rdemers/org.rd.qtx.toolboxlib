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
    internal/SQLite/shell.c \
    internal/SQLite/sqlite3.c \
    internal/DecNumber/decBasic.c \
    internal/DecNumber/decCommon.c \
    internal/DecNumber/decContext.c \
    internal/DecNumber/decDouble.c \
    internal/DecNumber/decimal32.c \
    internal/DecNumber/decimal64.c \
    internal/DecNumber/decimal128.c \
    internal/DecNumber/decNumber.c \
    internal/DecNumber/decPacked.c \
    internal/DecNumber/decQuad.c \
    internal/DecNumber/decSingle.c \
    internal/Udt4/api.cpp \
    internal/Udt4/buffer.cpp \
    internal/Udt4/cache.cpp \
    internal/Udt4/ccc.cpp \
    internal/Udt4/channel.cpp \
    internal/Udt4/common.cpp \
    internal/Udt4/core.cpp \
    internal/Udt4/epoll.cpp \
    internal/Udt4/list.cpp \
    internal/Udt4/md5.cpp \
    internal/Udt4/packet.cpp \
    internal/Udt4/queue.cpp \
    internal/Udt4/window.cpp \
    QtxDec/QDecContext.cpp \
    QtxDec/QDecDouble.cpp \
    QtxDec/QDecNumber.cpp \
    QtxDec/QDecPacked.cpp \
    QtxDec/QDecQuad.cpp \
    QtxDec/QDecSingle.cpp

HEADERS += \
    QtxToolboxLib.h \
    QtxToolboxLib_global.h \
    internal/SQLite/sqlite3.h \
    internal/SQLite/sqlite3ext.h \
    internal/DecNumber/decContext.h \
    internal/DecNumber/decDouble.h \
    internal/DecNumber/decDPD.h \
    internal/DecNumber/decimal32.h \
    internal/DecNumber/decimal64.h \
    internal/DecNumber/decimal128.h \
    internal/DecNumber/decNumber.h \
    internal/DecNumber/decNumberLocal.h \
    internal/DecNumber/decPacked.h \
    internal/DecNumber/decQuad.h \
    internal/DecNumber/decSingle.h \
    internal/Udt4/api.h \
    internal/Udt4/buffer.h \
    internal/Udt4/cache.h \
    internal/Udt4/ccc.h \
    internal/Udt4/channel.h \
    internal/Udt4/common.h \
    internal/Udt4/core.h \
    internal/Udt4/epoll.h \
    internal/Udt4/list.h \
    internal/Udt4/md5.h \
    internal/Udt4/packet.h \
    internal/Udt4/queue.h \
    internal/Udt4/udt.h \
    internal/Udt4/window.h \
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
