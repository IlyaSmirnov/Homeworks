#include <SharedPointerTests.h>

int main()
{
    SharedPointerTest test;
    QTest::qExec(&test);

    return 0;
}

