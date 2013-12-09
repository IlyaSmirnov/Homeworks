#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("%s\n", "Welcome to the programm which decomposes n into terms");

	int n = 0;
    printf("%s\n", "Enter n");
    scanf_s("%d", &n);
	
	int a[100000];
    for (int i = 0; i < n; i++)
        a[i] = 1;
    
    int temp = n - 1;

    while(a[1] != 0)
    {
        printf("%s", "\n");
        printf("%d%s", n, " = ");
        for (int i = 0; i < n; i++)
        {
            if ((i == n - 1) || (a[i+1] == 0))
            {
                printf("%d", a[i]);
                break;
            }

            printf("%d%s", a[i], " + ");
        }

        if ((a[temp] - 1 >= a[temp - 1] + 1) && (temp >= 1))
        {
			--a[temp];
			++a[temp - 1];
        }
        else
        {
			a[temp - 1] += a[temp];
			a[temp--] = 0;
        }
    }

	printf("\n");

	system("PAUSE");
	return 0;
}
