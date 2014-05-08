QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    hashTable.cpp \
    hashfunction.cpp

OTHER_FILES += \
    241.pro.user

HEADERS += \
    hashTable.h \
    hashfunction.h \
    hashTableTest.h

