#-------------------------------------------------
#
# Project created by QtCreator 2014-12-22T00:51:57
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 321
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    computer.cpp \
    localnet.cpp \
    windowscomputer.cpp \
    linuxcomputer.cpp \
    almostrandom.cpp \
    random.cpp \
    generator.cpp

HEADERS += \
    computer.h \
    localnet.h \
    tests.h \
    windowscomputer.h \
    linuxcomputer.h \
    almostrandom.h \
    random.h \
    generator.h
