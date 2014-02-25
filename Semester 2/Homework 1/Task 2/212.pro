TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pointerstack.cpp \
    arraystack.cpp \
    stack.cpp

HEADERS += \
    stack.h \
    pointerstack.h \
    arraystack.h

QMAKE_CXXFLAGS += -std=c++0x
