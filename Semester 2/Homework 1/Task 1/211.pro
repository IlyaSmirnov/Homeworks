QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    pointerlist.cpp \
    arraylist.cpp \
    list.cpp

HEADERS += \
    list.h \
    pointerlist.h \
    arraylist.h \
    listtest.h

QMAKE_CXXFLAGS += -std=c++0x
