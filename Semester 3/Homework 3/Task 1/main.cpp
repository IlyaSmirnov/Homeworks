#include "test.h"

int main()
{
	rTest test;
	QTest::qExec(&test);

	return 0;
}
