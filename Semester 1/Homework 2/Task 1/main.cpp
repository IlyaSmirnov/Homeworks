#include <stdio.h>
#include <stdlib.h>

int recur(int n)
{
    if ((n == 1) || (n == 2))
        return 1;
	else
        return recur(n - 2) + recur(n - 1);
}

int main()
{
    printf("%s\n", "Welcome to the programm of calculation of Fibonacci number");
    
	int n = 1;
    printf("%s\n", "Enter n");
    scanf_s("%d", &n);

	int fibit = 1;
    int fibit1 = 1;
    int fibit2 = 1;

    if ((n == 1) || (n == 2))
       fibit = 1;
    else
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                fibit1 += fibit2;
                if (i == n - 1)
                    fibit = fibit1;
            }
			else
			{
				fibit2 += fibit1;
				if (i == n - 1)
					fibit = fibit2;
			}
        }
    
    printf("%d\n", fibit);
	printf("%d\n", recur(n));

    system("PAUSE");
    return 0;
}
