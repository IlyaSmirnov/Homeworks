QT += xml
QT += network
QT += webkit
QT += core
QT += gui
QT += webkitwidgets
QT += xml
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rss
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
