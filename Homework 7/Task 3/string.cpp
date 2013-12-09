#include "string.h"

using namespace stringNS;

String stringNS::createString(int length)
{
	String string;
	string.length = 0;
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

	for (int i = 0; i < string.length; i++)
		result.string[i] = string.string[i];
	
	result.length = string.length;

	return result;
}

String stringNS::concatenationString(String &string1, String &string2)
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

bool stringNS::isEqualStrings(String &string1, String &string2)
{
	if (string1.length != string2.length)
		return false;

	for (int i = 0; i < string1.length; ++i)
		if (string1.string[i] != string2.string[i])
			return false;
	
	return true;
}

int stringNS::stringLength(String &string)
{
	return string.length;
}

bool stringNS::isEmptyString(String &string)
{
	return string.length == 0;
}

String stringNS::returnSubString(String &string, int firstElement, int length)
{
	String subString = createString(length);

	for (int i = 0; i < length; ++i)
		subString.string[i] = string.string[firstElement + i];

	subString.length = length;
	
	return subString;
}

char *stringNS::stringToChar(String &string)
{
	char *charString = new char[string.maxLength];

	for (int i = 0; i < string.maxLength; ++i)
		charString[i] = '\0';
	
	for (int i = 0; i < string.length; ++i)
		charString[i] = string.string[i];

	return charString;
}

String stringNS::charToStirng(char *string)
{
	String myString = createString(strlen(string));
	myString.length = strlen(string);
	myString.maxLength = 1000000;

	for (unsigned int i = 0; i < strlen(string); ++i)
		myString.string[i] = string[i];

	return myString;
}