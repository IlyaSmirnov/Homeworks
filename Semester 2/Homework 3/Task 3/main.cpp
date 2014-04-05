#include "mainwindow.h"
#include <QApplication>
#include "calculatorTest.h"

int main(int argc, char *argv[])
{
    calculatorTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
