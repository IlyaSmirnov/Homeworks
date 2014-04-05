#include "string.h"

using namespace string;

String string::create(int length)
{
	String string;
	string.length = 0;
	string.maxLength = length;
	string.string = new char[length];

	for (int i = 0; i < length; ++i)
	{
		string.string[i] = 0;
	}

	return string;
}

void string::deleteString(String &string)
{
	delete [] string.string;
}

String string::clone(String &string)
{
	String result = create(string.maxLength);

	for (int i = 0; i < string.length; i++)
		result.string[i] = string.string[i];
	
	result.length = string.length;

	return result;
}

String concatenation(String &string1, String &string2)
{
	String bigString;
	bigString.length = 0;
	bigString.maxLength = string1.length + string2.length;
	bigString.string = new char[bigString.maxLength];

	for (int i = 0; i < bigString.maxLength; ++i)
	{
		bigString.string[i] = 0;
	}

	int j = 0;

	for (int i = 0; i < string1.length; ++i)
	{
		
		bigString.string[j] = string1.string[i];
		++j;
	}
	
	for (int i = 0; i < string2.length; ++i)
	{

		bigString.string[j] = string2.string[i];
		++j;
	}

	deleteString(string1);

	return bigString;
}

bool isEqual(String &string1, String &string2)
{
	if (string1.length != string2.length)
		return false;

	for (int i = 0; i < string1.length; ++i)
		if (string1.string[i] != string2.string[i])
			return false;
	
	return true;
}

int stringLength(String &string)
{
	return string.length;
}

bool isEmpty(String &string)
{
	return string.length == 0;
}

String returnSubString(String &string, int firstElement, int length)
{
	String subString = create(length);

	for (int i = 0; i < length; ++i)
		subString.string[i] = string.string[firstElement + i];

	subString.length = length;
	
	return subString;
}

char stringToChar(String &string)
{
	char *charString = new char[string.maxLength];

	for (int i = 0; i < string.length; ++i)
		charString[i] = string.string[i];

	return *charString;
}