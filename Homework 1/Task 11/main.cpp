#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

void quickSort(int* a, int l, int r)
{
    int x = a[l + (r - l) / 2];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (a[i] < x)
            i++;
        
		while (a[j] > x)
			j--;
        
		if (i <= j)
        {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(a, i, r);

    if (l < j)
        quickSort(a, l, j);
}

int main()
{
    printf("%s\n", "Welcome to the program which can sort your array");
    
    int n = 0;
    printf("%s\n", "Enter n");
    scanf_s("%d", &n);

	int a[20];
    printf("%s\n", "Enter array");
	for (int i = 0; i < n; i++, a)
        scanf_s("%d", &a[i]);
    
	quickSort(a, 0, n - 1);

    printf("%s\n", "Sorted array");
	for (int i = 0; i < n; i++)
        printf("%d%c", a[i], ' ');
    
	printf("\n");

	system("PAUSE");
    return 0;
}
