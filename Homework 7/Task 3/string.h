#pragma once
#include <string.h>

namespace stringNS
{

	struct String
	{
		char *string;
		int maxLength;
		int length;
	};

	String createString(int length);
	void deleteString(String &string);
	String cloneString(String &string);
	String concatenationString(String &string1, String &string2);
	bool isEqualStrings(String &string1, String &string2);
	int stringLength(String &string);
	bool isEmptyString(String &string);
	String returnSubString(String &string, int firstElement, int length);
	char *stringToChar(String &string);
	String charToStirng(char *string);
}