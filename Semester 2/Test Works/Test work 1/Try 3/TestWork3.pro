CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

QT += core
QT -= gui
QT += testlib

TEMPLATE = app

SOURCES += main.cpp \
    pair.cpp \
    complexpair.cpp

HEADERS += \
    pair.h \
    complexpair.h \
    pairTest.h \
    compexPairTest.h

