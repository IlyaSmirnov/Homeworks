TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consolewriter.cpp \
    filewriter.cpp

HEADERS += \
    Writer.h \
    consolewriter.h \
    filewriter.h

