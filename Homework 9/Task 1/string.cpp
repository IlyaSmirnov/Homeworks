#include "string.h"

using namespace stringNS;

String stringNS::createString(int length)
{
	String string;
	string.maxLength = length;
	string.string = new char[length];

	for (int i = 0; i < length; ++i)
	{
		string.string[i] = '\0';
	}

	return string;
}

void stringNS::deleteString(String &string)
{
	delete [] string.string;
}

String stringNS::cloneString(String &string)
{
	String result = createString(string.maxLength);

	for (int i = 0; i < stringLength(string); i++)
		result.string[i] = string.string[i];

	return result;
}

String stringNS::concatenationString(String &string1, String &string2)
{
	String bigString;
	bigString.maxLength = string1.maxLength + string2.maxLength;
	bigString.string = new char[bigString.maxLength];

	for (int i = 0; i < bigString.maxLength; ++i)
	{
		bigString.string[i] = 0;
	}

	int j = 0;

	for (int i = 0; i < stringLength(string1); ++i)
	{
		
		bigString.string[j] = string1.string[i];
		++j;
	}
	
	for (int i = 0; i < stringLength(string2); ++i)
	{

		bigString.string[j] = string2.string[i];
		++j;
	}

	deleteString(string1);

	return bigString;
}

int stringNS::stringLength(String string)
{
	return strlen(string.string);
}

bool stringNS::isEqualStrings(String string1, String string2)
{
	if (stringLength(string1) != stringLength(string2))
		return false;

	for (int i = 0; i < stringLength(string2); ++i)
		if (string1.string[i] != string2.string[i])
			return false;
	
	return true;
}

bool stringNS::isEmptyString(String string)
{
	return stringLength(string) == 0;
}

String stringNS::returnSubString(String string, int firstElement, int length)
{
	String subString = createString(length);

	for (int i = 0; i < length; ++i)
		subString.string[i] = string.string[firstElement + i];

	return subString;
}

char *stringNS::stringToChar(String string)
{
	char *charString = new char[string.maxLength];

	for (int i = 0; i < string.maxLength; ++i)
		charString[i] = '\0';
	
	for (int i = 0; i < stringLength(string); ++i)
		charString[i] = string.string[i];

	return charString;
}

String stringNS::charToStirng(char *string)
{
	String myString = createString(strlen(string));
	myString.maxLength = 1000000;

	for (unsigned int i = 0; i < strlen(string); ++i)
		myString.string[i] = string[i];

	return myString;
}