#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int gcd(int i, int j)
{
    while (i && j)
		if (i >= j)
			i %= j;
        else
			j %= i;

	return i | j;
}

int main()
{
	printf("%s\n", "Welcome to the programm which print every simple irreducible fractions whose denominator is less than n");

    int n = 0;
	printf("%s\n", "Enter n");
	scanf_s("%d", &n);

    int k = 0;
    int numerator[100000];
    int denominator[100000];

    for (int i = 0; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (gcd(i, j) == 1)
            {
                numerator[k] = j;
                denominator[k] = i;
                k++;
            }
        
    for (int i = 0; i < k; i++)
        for (int j = 0; j < i - 1; j++)
            if ((numerator[i]) / static_cast<float>(denominator[i]) < (numerator[j]) / static_cast<float>(denominator[j]))
            {
                swap(&numerator[i], &numerator[j]);
                swap(&denominator[i], &denominator[j]);
            }
    
    for (int i = 0; i < k; i++)
        printf("%d%s%d\n", numerator[i], "/", denominator[i]);
    
	system("PAUSE");
	return 0;
}
