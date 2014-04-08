QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
QT += core
QT -= gui

SOURCES += main.cpp

HEADERS += \
    SharedPointer.h \
    SharedPointerTests.h \
    pointer.h

