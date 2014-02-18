TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pointerlist.cpp \
    arraylist.cpp \
    list.cpp

HEADERS += \
    list.h \
    pointerlist.h \
    arraylist.h

QMAKE_CXXFLAGS += -std=c++0x
