#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s\n", "Welcome to the program which transfer symbols in number n with purpose to get minimum");

	long long n = 0;
    printf("%s\n", "Enter n");
    scanf_s("%lld", &n);

    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (n > 0)
    {
        ++count[n % 10];
        n /= 10;
    }

    if (count[0] != 0)
        for (int i = 1; i < 10; i++)
            if(count[i] != 0)
            {
                printf("%d", i);
				--count[i];
                break;
            }
    

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d", i);
    
	printf("\n");

	system("pause");
	return 0;
}
