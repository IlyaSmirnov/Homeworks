#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "float.h"

using namespace std;
using namespace floatNS;

char *createString(int stringLength);
bool preSecondOrderOperation(char *string, int &currentPosition);
bool preFirstOrderOperation(char *string, int &currentPosition);
bool secondOrderOperation(char *string, int &currentPosition);
bool firstOrderOperation(char *string, int &currentPosition);
bool floatNumber(char *string, int &currentPosition);

int main()
{
	cout << "Welcome to the program of parsing" << endl;
	cout << "Enter string you want to analyze ";

	const int stringLength = 255;
	char *string = createString(stringLength);
	
	cin >> string;

	int currentPosition = 0;

	cout << ((preSecondOrderOperation(string, currentPosition) && (string[currentPosition] == '\0')) ? "Your string is arithmetic expression" : "Your string is not arithmetic expression") << endl;

	delete [] string;

	system("pause");
	return 0;
}

char *createString(int stringLength)
{
	char *string = new char[stringLength];

	for (int i = 0; i < stringLength; ++i)
		string[i] = '\0';

	return string;
}

bool preSecondOrderOperation(char *string, int &currentPosition)
{
	return ((preFirstOrderOperation(string, currentPosition)) && (secondOrderOperation(string, currentPosition)));
}

bool preFirstOrderOperation(char *string, int &currentPosition)
{
	return ((floatNumber(string, currentPosition)) && (firstOrderOperation(string, currentPosition)));
}

bool secondOrderOperation(char *string, int &currentPosition)
{
	if ((string[currentPosition] != '+') && (string[currentPosition] != '-'))
		return true;

	++currentPosition;

	return ((preFirstOrderOperation(string, currentPosition)) && (secondOrderOperation(string, currentPosition)));
}

bool firstOrderOperation(char *string, int &currentPosition)
{
	if ((string[currentPosition] != '*') && (string[currentPosition] != '/'))
		return true;

	++currentPosition;

	return ((floatNumber(string, currentPosition)) && (firstOrderOperation(string, currentPosition)));
}


bool floatNumber(char *string, int &currentPosition)
{
	if (string[currentPosition] == '(')
	{
		++currentPosition;

		bool check = preFirstOrderOperation(string, currentPosition);

		if (string[currentPosition] != ')')
			return false;

		++currentPosition;

		return check;
	}

	return (isFloat(string, currentPosition));
}