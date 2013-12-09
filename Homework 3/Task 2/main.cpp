#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%s\n", "Welcome to the programm which print your array of n^2 elements in spiral oreder");

	int n = 0;
	printf("%s\n", "Enter n");
	scanf_s("%d", &n);

	int array[100][100];
	int i = 0;
	int j = 0;
	printf("%s\n", "Enter your array");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &array[i][j]);

	int array1[10000];
  
	int i1 = n;
    int j1 = n;
    int temp = 0;
    j = n - j1;

    while (j < j1)
    {
        i = n - i1;
        j = n - j1;
        for (; j < j1; j++)
        {
                array1[temp] = array[i][j];
                temp++;
        }

        j--;
        
		for (i++; i < i1; i++)
        {
            array1[temp] = array[i][j];
            temp++;
        }

        i--;
        
		for (j--; j >= n - j1; j--)
        {
            array1[temp] = array[i][j];
            temp++;
        }

        j++;
        
		for (i--; i > n - j1; i--)
        {
            array1[temp] = array[i][j];
            temp++;
        }
        
		i++;
        i1--;
        j1--;
    }

    for (int i = n * n - 1; i >= 0; i--)
        printf("%5d", array1[i]);

    system("pause");
	return 0;
}
