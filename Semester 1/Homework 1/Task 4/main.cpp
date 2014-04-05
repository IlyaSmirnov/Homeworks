#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s", "Number of lucky tickets: ");
    int count = 0;

	for (int i = 000000; i <= 999999; ++i)
    {
        int i1 = i / 100000;
        int i2 = i / 10000 - i1 * 10;
        int i3 = i / 1000 - i1 * 100 - i2 * 10;
        int i4 = i / 100 - i1 * 1000 - i2 * 100 - i3 * 10;
        int i5 = i / 10 - i1 * 10000 - i2 * 1000 - i3 * 100 - i4 * 10;
        int i6 = i - i1 * 100000 - i2 * 10000 - i3 * 1000 - i4 * 100 - i5 * 10;

        int half1 = i1 + i2 + i3;
        int half2 = i4 + i5 + i6;

        if (half1 == half2)
            ++count;
    }

    printf("%d\n", count);

	system("PAUSE");
    return 0;
}
