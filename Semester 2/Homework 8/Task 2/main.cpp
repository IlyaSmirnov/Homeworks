#include <QApplication>

#include "bash.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bash w;
    w.show();

    return a.exec();
}
