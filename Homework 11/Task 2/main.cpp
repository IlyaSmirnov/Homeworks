#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char * createString(int stringLength)
{
	char *string = new char[stringLength];
	for (int i = 0; i < stringLength; ++i)
		string[i] = '\0';

	return string;
}

bool isSign(char symbol)
{
	return ((symbol == '+') || (symbol <= '-'));
}

bool isNumber(char symbol)
{
	return ((symbol >= '0') && (symbol <= '9'));
}

bool isDot(char symbol)
{
	return (symbol == '.');
}

bool isEnd(char symbol)
{
	return (symbol == '\0');
}

bool isE(char symbol)
{
	return symbol == 'E';
}

bool isFloat(char* string)
{
	enum states { start, integer, dot, afterDot, e, signAfterE, numberAferE, finish, fail };
	states state = start;

	int i = -1;
	int stringLength = strlen(string);

	while (i <= stringLength)
	{
		switch (state)
		{
		case start:
		{
			++i;

			if (isSign(string[i]) || (isNumber(string[i])))
				state = integer;
			else
				state = fail;

			break;
		}

		case integer:
		{
			++i;

			if (isNumber(string[i]))
			{
				state = integer;
				break;
			}

			if (isDot(string[i]))
			{
				state = dot;
				break;
			}

			if (isEnd(string[i]))
			{
				state = finish;
				break;
			}

			if (isE(string[i]))
			{
				state = e;
				break;
			}

			state = fail;
			break;
		}

		case dot:
		{
			++i;

			if (isNumber(string[i]))
			{
				state = afterDot;
				break;
			}

			state = fail;
			break;
		}

		case afterDot:
		{
			++i;

			if (isNumber(string[i]))
			{
				state = afterDot;
				break;
			}

			if (isEnd(string[i]))
			{
				state = finish;
				break;
			}

			if (isE(string[i]))
			{
				state = e;
				break;
			}

			state = fail;
			break;
		}

		case e:
		{
			++i;

			if (isSign(string[i]))
			{
				state = signAfterE;
				break;
			}

			if (isE(string[i]))
			{
				state = e;
				break;
			}

			state = fail;
			break;
		}

		case signAfterE:
		{
			++i;

			if (isNumber(string[i]))
			{
				state = numberAferE;
				break;
			}

			if (isEnd(string[i]))
			{
				state = finish;
				break;
			}

			state = fail;
			break;
		}

		case numberAferE:
		{
			++i;

			if (isNumber(string[i]))
			{
				state = numberAferE;
				break;
			}

			if (isEnd(string[i]))
			{
				state = finish;
				break;
			}

			state = fail;
			break;
		}

		case finish:
		{
			return true;
		}

		case fail:
		{
			return false;
		}

		}
	}
}

int main()
{
	cout << "Welcome to the program which can tell you either your string is float number or not" << endl;
	cout << "Enter your string ";

	const int stringLength = 255;
	char *string = createString(stringLength);

	cin >> string;

	cout << (isFloat(string) ? "It is float number" : "It is not float number") << endl;
	
	delete []string;

	system("pause");
	return 0;
}