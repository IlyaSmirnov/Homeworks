#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(char* string)
{
    bool check = true;

    int i = 0;
    int j = strlen(string) - 1;

    while (i < j)
    {
        if (string[i] != string[j])
            check = false;
        
        i++;
        j--;
    }

    return check;
}

int main()
{
    char* string = new char[1000];
    scanf_s("%s", string);

    if (isPalindrome(string))
        printf("%s", "YES");
    else
      printf("%s", "NO");
    
	system("PAUSE");
    return 0;
}
