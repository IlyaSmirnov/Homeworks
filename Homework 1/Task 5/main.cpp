#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("%s\n", "Enter brackets sequence");
	char* string = new char[1000];
	scanf_s("%s", string);
	int counter = 0;
	bool balance = false;

	for (int i = 0; i < strlen(string); ++i)
	{
		if ((string[i] == '('))
			++counter;

		if ((string[i] == ')') && (counter <= 0))
			balance = true;

		if ((string[i] == ')') && (counter > 0))
			--counter;

		if ((string[i] == ')') && (counter == 0))
			balance = true;
	}

	if ((!balance) && (counter == 0))
		printf("%s\n", "Balance is ok");
	else
		printf("%s\n", "Balance is not ok");

	system("PAUSE");
	return 0;
}