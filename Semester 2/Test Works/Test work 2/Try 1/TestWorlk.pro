QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
QT += core
QT -= gui

SOURCES += main.cpp \
    intAscendingComparator.cpp \
    intDiscendingComparator.cpp \
    CharComparator.cpp

HEADERS += \
    BubbleSort.h \
    BubbleTest.h \
    comparator.h \
    intAscendingComparator.h \
    intDiscendingComparator.h \
    charComparator.h

