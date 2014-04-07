QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    consolewriter.cpp \
    filewriter.cpp \
    writer.cpp

HEADERS += \
    consolewriter.h \
    filewriter.h \
    writer.h \
    WriterTest.h

