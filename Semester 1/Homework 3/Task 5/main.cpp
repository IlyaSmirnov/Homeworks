#include "CircularList.h"
#include <stdlib.h>
#include <stdlib.h>

using namespace lists;

int main()
{
	printf_s("%s\n", "Welcome to the program Counting");
	printf_s("%s\n", "Enter the number soldiers");
	int n = 0;
	scanf_s("%d", &n);

	printf_s("%s\n", "Enter the number soldiers");
	int m = 0;
	scanf_s("%d", &m);

	CircularList *list = new CircularList;

	for (int i = 1;  i <= n; ++i)
	{
		list->addEl(i);
	}

	int i = 1;
	int k = 1;
	ListElement *temp;

	temp = list->head;

	while (list->head->value != list->tail->value)
	{
		if ((k % m) == 0)
		{
			k = 1;
			ListElement *copyTemp;
			copyTemp = temp->next;
			list->deleteElement(temp);
			temp = copyTemp;
			continue;
		}
		++k;
		temp = temp->next;
	}

	printf("%d\n", list->head->value);

	list->deleteElement(list->head);

	list->deleteList();
	delete list;

	system("PAUSE");
	return 0;
}
