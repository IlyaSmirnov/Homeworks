#include "sortedLists.h"
#include <stdlib.h>

using namespace list;

int main()
{
	printf_s("%s\n", "Welcome to the program of the list");
	printf_s("%s\n", "Enter the number and then something would happen!");
	printf_s("%s\n", "Enter 0 - exit");
	printf_s("%s\n", "Enter 1 - add a value to sorted list");
	printf_s("%s\n", "Enter 2 - remove a value from sorted list");
	printf_s("%s\n", "Enter 3 - print list");

	int n = 4;
	SortedList *list = new SortedList;
	int value = 0;
	
	while (n != 0)
	{
		scanf_s("%d", &n);
		switch (n)
		{
			case 0:
			{
				list->deleteList();
				break;
			}

			case 1:
			{
				printf_s("%s\n", "Enter value");
				scanf_s("%d", &value);
				list->addValue(value);
				break;
			}

			case 2:
			{
				printf_s("%s\n", "Enter value");
				scanf_s("%d", &value);
				list->removeValue(value);
				break;
			}

			case 3:
			{
				printf_s("%s\n", "List:");
				list->show();
				break;
			}
		}
	}
	
	return 0;
}
