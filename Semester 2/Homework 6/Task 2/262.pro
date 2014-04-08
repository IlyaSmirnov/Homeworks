QT += testlib
CONFIG += c++11
QT       += core
QT       -= gui
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SOURCES += main.cpp \
    list.cpp \
    uniquelist.cpp

HEADERS += \
    list.h \
    listtest.h \
    uniquelist.h \
    MyError.h

QMAKE_CXXFLAGS += -std=c++0x
