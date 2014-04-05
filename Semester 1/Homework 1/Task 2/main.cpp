#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int b = 0;
    int mod = -1;

    printf("%s\n", "Welcome to the programm of calculation of partial quotient a to b");
    printf("%s\n", "Enter a and b");
    scanf_s("%d", &a);
	scanf_s("%d", &b);

    while (a > 0)
    {
        a = a - b;
        ++mod;
    }

    printf("%s%d\n", "mod(a,b) = ", mod);
	
	system("PAUSE");
    return 0;
}