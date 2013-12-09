#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;



bool isSmallLetter(char stringElement)
{
	return ((stringElement >= 'a') && (stringElement <= 'z'));
}

bool isBigLetter(char stringElement)
{
	return ((stringElement >= 'A') && (stringElement <= 'Z'));
}

bool isLetter(char stringElement)
{
	return ((isSmallLetter(stringElement)) || (isBigLetter(stringElement)));
}


int main()
{
	fstream in("input1.txt");

	const int englishAlphabetPower = 25;
	const int stringLength = 255;

	char *string = new char[stringLength];
	bool chck[englishAlphabetPower];

	for (int j = 0; j < englishAlphabetPower; j++)
		chck[j] = false;
	
	if (!in.is_open())
	{
		printf("%s\n", "Your file is not exist");
	}
	else
	{
		printf("%s\n", "The first mentions of the letter in each word from your text");

		while (!in.eof())
		{
			in.getline(string, stringLength);

			for (int i = 0; i < strlen(string); i++)
			{
				if (isLetter(string[i]))
				{
				if ((isSmallLetter(string[i])) && (!chck[(int) string[i] - (int)'a']))
					{
						printf("%c", string[i]);
						chck[(int) string[i] - (int)'a'] = true;
					}

				if ((isBigLetter(string[i])) && (!chck[(int) string[i] - (int)'A']))
					{
					printf("%c", string[i]);
					chck[(int) string[i] - (int)'A'] = true;
					}
				}
				else
				{
					for (int j = 0; j < englishAlphabetPower; j++)
						chck[j] = false;
					printf("%c", ' ');
				}
			}
			printf("\n");
		}
	}

	delete[] string;
	in.close();

	system("PAUSE");
	return 0;
}