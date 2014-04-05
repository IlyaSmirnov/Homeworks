#include <stdio.h>
#include <stdlib.h>

int main()
{
	int const amountTextConstants = 91;
	int const stringLength = 10;

	const char** textConstants = new const char* [amountTextConstants];
	textConstants[1] = "one ";
	textConstants[2] = "two ";
	textConstants[3] = "three ";
	textConstants[4] = "four ";
	textConstants[5] = "five ";
	textConstants[6] = "six ";
	textConstants[7] = "seven ";
	textConstants[8] = "eight ";
	textConstants[9] = "nine ";
	textConstants[10] = "ten ";
	textConstants[11] = "eleven ";
	textConstants[12] = "twelve ";
	textConstants[13] = "thirteen ";
	textConstants[14] = "fourteen ";
	textConstants[15] = "fifteen ";
	textConstants[16] = "sixteen ";
	textConstants[17] = "seventeen ";
	textConstants[18] = "eighteen ";
	textConstants[19] = "nineteen ";
	textConstants[20] = "twenty-";
	textConstants[30] = "thirty-";
	textConstants[40] = "forty-";
	textConstants[50] = "fifty-";
	textConstants[60] = "sixty-";
	textConstants[70] = "seventy-";
	textConstants[80] = "eighty-";
	textConstants[90] = "ninety-";

	printf("%s\n", "Welcome to the programm which print your number as word");
	printf("%s", "Enter number: ");

	int n = 0;
	scanf_s("%d", &n);

	int numbers[6];
	numbers[0] = n % 10;
	numbers[1] = n / 10 % 10;
	numbers[2] = n / 100 % 10;
	numbers[3] = n / 1000 % 10;
	numbers[4] = n / 10000 % 10;
	numbers[5] = n / 100000 % 10;

	printf("%s", "Your number as word: ");

	if (numbers[5])
	{
		printf("%s", textConstants[numbers[5]]);
		printf("%s", "hundred ");
	}

	if (numbers[4])
	{
		if (numbers[4] == 1)
			printf("%s", textConstants[numbers[4] * 10 + numbers[3]]);
		else 
		{
			printf("%s", textConstants[numbers[4] * 10]);
			printf("%s", textConstants[numbers[3]]);
		}
	}
	else
		if (numbers[3])
			printf("%s", textConstants[numbers[3]]);
			
	if (n > 999)
		printf("%s", "thousand ");

	if (numbers[2])
	{
		printf("%s", textConstants[numbers[2]]);
		printf("%s", "hundred ");
	}
	
	if ((numbers[0] + numbers[1] * 10) && (n > 99))
		printf("%s", "and ");

	if (numbers[1])
	{
		if (numbers[1] == 1)
			printf("%s", textConstants[numbers[1] * 10 + numbers[0]]);
		else
		{
			printf("%s", textConstants[numbers[1] * 10]);
			printf("%s", textConstants[numbers[0]]);
		}
	}
	else
		if (numbers[0])
			printf("%s", textConstants[numbers[0]]);

	if (n == 0)
		printf("%s", "zero");

	printf("\n");

	delete [] textConstants;

	system("PAUSE");
	return 0;
}