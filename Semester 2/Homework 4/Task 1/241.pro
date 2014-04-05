QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    hashTable.cpp \
    hashfunction.cpp

OTHER_FILES +=

HEADERS += \
    hashTable.h \
    hashfunction.h

