#include <stdio.h>
#include <stdlib.h>

int pow(int a, int n)
{
	int res = 1;

	while (n)
	{
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}

	return res;
}

int main()
{
	printf("%s\n", "Welcome to the programm of exponentiation a^n");

	int a = 0;
	printf("%s\n", "Enter a");
	scanf("%d", &a);

	int n = 0;
	printf("%s\n", "Enter n");
	scanf("%d", &n);

	printf("%d\n", pow(a, n));

	system("PAUSE");
	return 0;
}