#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

void printComment(char* string, int i)
{
	for (int j = i; j <= strlen(string) - 1; ++j)
	{
		printf("%c", string[j]);
	}
}

int main()
{
	fstream in("input3.txt");

	const int stringLength = 255;

	char *string = new char[stringLength];

	bool inBigComment;
	inBigComment = false;
	bool inTextString;
	inTextString = false;
	bool isAlreadyPrinted;
	isAlreadyPrinted = false;

	if (!in.is_open())
	{
		printf("%s\n", "Your file is not exist");
	}
	else
	{
		printf("%s\n", "Comments from your file:");

		while (!in.eof())
		{
			in.getline(string, stringLength);
			for (int i = 0; i < strlen(string) - 1; ++i)
			{
				if ((string[i] == '/') && (string[i + 1] == '/') && (!isAlreadyPrinted) && (!inTextString) && (!inBigComment))
				{
					printComment(string, i);
					isAlreadyPrinted = true;
				}

				if (((string[i] == '/') && (string[i + 1] == '*')) && (!inBigComment))
					inBigComment = true;

				if (((string[i] == '*') && (string[i + 1] == '/')) && (inBigComment))
					inBigComment = false;

				if (string[i] == '\"')
					inTextString = !inTextString;
			}
			if (string[strlen(string) - 1] == '\"')
			{
				inTextString = !inTextString;
			}
			isAlreadyPrinted = false;
			printf("\n");
		}
	}

	delete[] string;
	in.close();

	system("PAUSE");
	return 0;
}