#-------------------------------------------------
#
# Project created by QtCreator 2014-03-08T21:57:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 233
TEMPLATE = app

QT += testlib

SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    calculatorTest.h

FORMS    += mainwindow.ui
