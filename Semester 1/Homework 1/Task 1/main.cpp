#include <iostream>
#include <stdlib.h>

int main()
{
	int x = 0;
	printf("%s\n", "Enter x");
	scanf_s("%d", &x);

	int squarex = x * x;

	printf("%s%d\n", "x^4 + x^3 + x^2 + x = ", (squarex + x) * (squarex + 1));
	
	system("PAUSE");
	return 0;
}