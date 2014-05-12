#include "compexPairTest.h"
#include "pairTest.h"

int main()
{
    PairTest pairTest;
    QTest::qExec(&pairTest);
    ComplexPairTest complexPairTest;
    QTest::qExec(&complexPairTest);

    return 0;
}

