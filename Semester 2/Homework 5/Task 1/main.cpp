#include <QFile>

#include "parsetree.h"
#include "test.h"

using namespace std;

int main()
{
    Test test;
    QTest::qExec(&test);

    QFile file("input.txt");

    if (!file.open(QIODevice::ReadOnly))
        return 0;

    QString string;
    string.clear();
    string = file.readAll();

    ParseTree *parser = new ParseTree();

    parser->print(string);

    cout << parser->calculate(string);

    delete parser;

    return 0;
}

