QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
QT += core
QT -= gui

SOURCES += main.cpp \
    parsetree.cpp \
    operandnode.cpp \
    operatornode.cpp \
    treenode.cpp

HEADERS += \
    treenode.h \
    parsetree.h \
    operandnode.h \
    operatornode.h \
    test.h

OTHER_FILES += \
    ../build-261-Desktop_Qt_5_2_1_MinGW_32bit-Debug/input.txt

