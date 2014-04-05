#include <stdio.h>
#include <stdlib.h>

void downHeap(int a[], int k, int n)
{
    int newElt = a[k];

    while (k <= n / 2)
    {
        int child = 2 * k;

        if ((child < n) && (a[child] < a[child + 1]))
            child++;
        
		if (newElt >= a[child])
            break;
        
		a[k] = a[child];
        k = child;
    }

    a[k] = newElt;

	return;
}

void heapSort(int a[], int n)
{
	for (int i = n / 2; i >= 1; --i)
        downHeap(a, i, n);

	for (int i = n; i > 1; --i)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        downHeap(a, 1, i - 1);
    }

	return;
}

int main()
{
	printf("%s\n", "Wecome in the programm of the sort of array of n elements");

    int n = 0;
    printf("%s\n", "Enter n");
    scanf_s("%d", &n);

	int a[10000];
    printf("%s\n", "Enter array");
    for (int i = n; i > 0; --i)
    {
		scanf_s("%d", &a[i]);
        downHeap(a, i, n);
    }

    heapSort(a, n);

    for (int i = 1; i <= n; ++i)
        printf ("%d%s", a[i], " ");
    
	system("PAUSE");
	return 0;
}
