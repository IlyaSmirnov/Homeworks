#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool checkStr(int i, char* string1, char* string2)
{
    bool check = true;

    for (unsigned int k = 0; k < strlen(string2); ++k)
        if (string2[k] != string1[i + k])
            check = false;

    return check;
}

int main()
{
    printf("%s\n", "Welcome to the programm of counting occurrences of a substring in a string");

    char* string = new char[1000];
    printf("%s\n", "Enter string");
	scanf_s("%s", string);

	char* substring = new char[1000];
    printf("%s\n", "Enter substring");
	scanf_s("%s", substring);

    int counter = 0;

	for (unsigned int i = 0; i < (strlen(string) - strlen(substring) + 1); ++i)
    {
		if ((string[i] == substring[0]) && (checkStr(i, string, substring)))
            ++counter;
    }

    printf("%d", counter);

	system("PAUSE");
    return 0;
}
