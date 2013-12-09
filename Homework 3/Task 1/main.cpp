#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
    printf("%s\n", "Welcome to the program which print YES if you can get the first string from the second one by moving symbols and NO if you not");

    char* string1 = new char[1000];
    printf("%s\n", "Enter the first string");
    scanf("%s", string1);

	char* string2 = new char[1000];
    printf("%s\n", "Enter the second string");
    scanf("%s", string2);

    int a[255];
    for (int i = 0; i < 255; i++)
        a[i] = 0;
 
	for (unsigned int i = 0; i < strlen(string1); i++)
		++a[static_cast<int>(string1[i])];
    

    for (unsigned int i = 0; i < strlen(string2); i++)
        --a[static_cast<int>(string2[i])];
 
    bool b = true;

    for (int i = 0; i < 255; i++)
        if (a[i] != 0)
            b = false;
   
    if (b)
        printf("%s\n", "YES");
    else
        printf("%s\n", "NO");
   
	system("PAUSE");
    return 0;
}