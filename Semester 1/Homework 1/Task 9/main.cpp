#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int n = 0;
    int pow = 1;

    printf("%s", "Enter a ");
    scanf_s("%d", &a);
    printf("%s", "Enter n ");
	scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
        pow *= a;
    
    printf("%d\n", pow);

	system("PAUSE");
    return 0;
}
