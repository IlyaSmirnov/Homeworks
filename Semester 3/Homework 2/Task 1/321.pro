#-------------------------------------------------
#
# Project created by QtCreator 2014-12-20T22:36:41
#
#-------------------------------------------------

QT       += testlib

QT       += core

QT       -= gui

TARGET = 321
CONFIG   += console
CONFIG   -= app_bundle
CONGIF += c++11

TEMPLATE = app


SOURCES += main.cpp \
    computer.cpp \
    localnet.cpp

HEADERS += \
    computer.h \
    localnet.h \
    tests.h
