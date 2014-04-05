QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    bubblesort.cpp \
    quicksort.cpp \
    heapsort.cpp

HEADERS += \
    Sorter.h \
    bubblesort.h \
    quicksort.h \
    heapsort.h \
    sortertest.h

