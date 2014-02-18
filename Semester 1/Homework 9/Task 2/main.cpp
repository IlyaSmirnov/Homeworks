#include <iostream>
#include "string.h"
#include <stdlib.h>

using namespace std;

int hashFunction(char* string)
{
	int hash = 0;
	
	for (int i = 0; i < strlen(string); i++)
		hash = (string[i] + hash * 239) % 4139;

	return hash;
}

int charHashFunction(char string)
{
	return (int) string;
}

int rabinKarp(char* string, char* substring)
{
	if (strlen(string) < strlen(substring))
		return 0;

	int hashOfSubstring = hashFunction(substring);
	
	int hash = 0;
	for (int i = 0; i < strlen(substring); i++)
		hash = (string[i] + hash * 239) % 4139;
	
	int pow = 1;
	for (int i = 0; i < strlen(substring); i++)
		pow *= 239;

	int number = 0;
	if (hash == hashOfSubstring)
		++number;
	for (int i = 0; i < strlen(string) - strlen(substring); ++i)
	{
		if (hash == hashOfSubstring)
			++number;

		hash = hash * 239 - charHashFunction(string[i]) + charHashFunction(string[i + strlen(substring)]);
	}

	return number;
}

int main()
{
	cout << "Welcome to the program of Rabin-Karp algorythm" << endl;

	const int stringLength = 255;

	cout << "Enter your string" << endl;
	char* string = new char[255];
	cin >> string;

	cout << "Enter your substring" << endl;
	char* substring = new char[255];
	cin >> substring;

	int number = rabinKarp(string, substring);
	if (number != 0)
		cout << "The number of contents substring in string is " << rabinKarp(string, substring) << endl;
	else
		cout << "Yout string don't contain substring" << endl;
	
	delete [] string;
	delete [] substring;
	
	system("PAUSE");
	return 0;
}