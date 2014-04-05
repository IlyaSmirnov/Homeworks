#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int m = 0;
    int segment[300];
    int first = 0;

    printf("%s\n", "Enter n and m");
	scanf_s("%d%d", &n, &m);
    printf("%s\n", "Enter segment");

	for (int i = 0; i < (n + m); ++i)
        scanf_s("%d", &segment[i]);
    
	for (int i = 0; i < n; ++i)
    {
        first = segment[0];
		for (int j = 0; j < (n + m - 1); ++j)
            segment[j] = segment[j + 1];
        segment[m + n - 1] = first;
    }

    printf("%s\n", "New segment");

	for (int i = 0; i < (n + m); ++i)
		printf("%d%c", segment[i], ' ');
    
	system("PAUSE");
    return 0;
}

