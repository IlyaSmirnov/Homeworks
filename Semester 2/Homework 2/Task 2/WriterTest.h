#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "consolewriter.h"

class WriterTest : public QObject
{
    Q_OBJECT
public:
    explicit WriterTest(QObject *parent = 0)
    {

    }

    ~WriterTest()
    {
        delete writer;
    }

private slots:
    void checkSize()
    {
        int** matrix = new int*[2];

        for (int i = 0; i < 2; ++i)
            matrix[i] = new int[2];

        int k = 1;

        for (int j = 0; j < 2; ++j)
            for (int i = 0; i < 2; ++i)
            {
                matrix[i][j] = k;
                ++k;
            }


        QVERIFY( writer->write(matrix, 2) == false);
    }

private:
    Writer *writer = new ConsoleWriter;
};

