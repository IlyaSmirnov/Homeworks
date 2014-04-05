#include "list.h"
#include <stdlib.h>

using namespace lists;

int main()
{
	printf_s("%s\n", "Welcome to the program of sort of the list");
	printf_s("%s\n", "Enter number of elements in list");
	int n = 0;
	scanf_s("%d", &n);
	printf_s("%s\n", "Enter elements of list");
	List *list = new List;
	for (int i = 0; i < n; ++i)
	{
		int value = 0;
		scanf_s("%d", &value);
		list->addEl(value);
	}
	
	list->head = list->sortList(list->head);

	printf_s("%s\n", "Sorted list:");

	list->show();

	list->deleteList();
	system("PAUSE");
	delete list;
	return 0;
}