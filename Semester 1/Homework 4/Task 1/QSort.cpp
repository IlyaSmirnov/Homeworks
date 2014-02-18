#include "QSort.h"
using namespace QSortAlgorith;

void QSortAlgorith::quickSort(int* a, int l, int r)
{
	int x = a[l + (r - l) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < x)
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
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