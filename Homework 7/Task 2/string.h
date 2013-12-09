#pragma once

namespace string
{

	struct String
	{
		char *string;
		int maxLength;
		int length;
	};

	String create(int length);
	void deleteString(String &string);
	String clone(String &string);
	String concatenation(String &string1, String &string2);
	bool isEqual(String &string1, String &string2);
	int stringLength(String &string);
	bool isEmpty(String &string);
	String returnSubString(String &string, int firstElement, int length);
	char StringToChar(String &string);
}