#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include "QSort.h"

using namespace QSortAlgorith;


int main()
{
	printf("%s\n", "Welcome to the program which would print max element in your wich you can meet in it twice or even more often");
	int a[20];

	int n = 0;
	printf("%s\n", "Enter n");
	scanf_s("%d", &n);
	printf("%s\n", "Enter array");
	for (int i = 0; i < n; i++, a)
	{
		scanf_s("%d", &a[i]);
	}
	quickSort(a, 0, n - 1);

	bool chck = false;
	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i] == a[i + 1])
		{
			printf("%s", "Max element in your wich you can meet in it twice or even more often:");
			printf("%d\n", a[i]);
			chck = true;
			break;
		}
	}
	if (!chck)
		printf("%s\n", "All elements in your array you can meet only once");
	system("PAUSE");
	return 0;
}
