#include <stdio.h>
#include <stdlib.h>

int recur(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * recur(n - 1);
    }
}

int main()
{
    int n = 1;
    int factit = 1;

    printf("%s\n", "Enter n");
    scanf_s("%d", &n);

	for (int i = 2; i <= n; ++i)
       factit *= i;
   
    printf("%d\n", factit);

    printf("%d\n", recur(n));

	system("PAUSE");
    return 0;
}
