#include <stdio.h>
#include <math.h>
#include <stdlib.h>

bool checkPrime(int number)
{
    int mods = 0;
    bool isPrime = false;

	for (int i = 2; i < number; ++i)
        if (number % i == 0)
            ++mods;
    
    if (mods > 0)
        isPrime = true;
    
	return isPrime;
}

int main()
{
    int n = 0;

	printf("%s\n%s\n", "Welcome to the programm of the output of all prime numbers which less than n", "Enter n");
    scanf_s("%d", &n);
    printf("%s\n", "Prime numbers:");

    for (int i = 2; i <= n; ++i)
        if (!checkPrime(i))
            printf("%d%c", i, ' ');
   
	printf("\n");

	system("PAUSE");
    return 0;
}
