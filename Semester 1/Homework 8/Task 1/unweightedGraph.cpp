#include "unweightedGraph.h"

using namespace list;
using namespace std;

List list::create()
{
	List list;
	list.head = nullptr;
	list.name = ' ';
	list.visit = false;
	return list;
}

void list::deleteList(List &list)
{
	while (list.head != nullptr)
	{
		ListElement *temp = list.head->next;
		delete list.head;
		list.head = temp;
	}

	delete list.head;
}

void list::addEl(List &list, int value)
{
	ListElement *temp = new ListElement;
	temp->value = value;

	if (list.head != nullptr) 
	{
		temp->next = list.head;
		list.head = temp;
	}
	else
	{
		temp->next = nullptr;
		list.head = temp;
	}
}

void list::deleteElement(List &list, ListElement *&listElement)
{
	ListElement *counter = list.head;
	ListElement *temp;

	if ((list.head != nullptr) && (list.head != listElement))
	{
		while ((counter != nullptr) && (counter->next != listElement))
			counter = counter->next;
		if (counter)
		{
			temp = counter->next;
			counter->next = counter->next->next;
			delete temp;
			return;
		}
	}
	else
	{
		if (list.head != listElement)
		{
			temp = listElement;
			list.head = listElement->next;
			delete temp;
			return;
		}
	}
}

void list::DFS(List graph[], int i, int number)
{
	ListElement *temp = graph[i].head;
	graph[i].name = (char) number + 'A';
	++number;
	graph[i].visit = true;
	cout << i << ' ' << graph[i].name << endl;
	while (temp != nullptr)
	{
		if (!graph[temp->value].visit)
			DFS(graph, temp->value, number);
		temp = temp->next;
	}
}


void list::show(List &list, int i)
{
	ListElement *temp = list.head;
	while (temp != nullptr)
	{
		printf("%d%c%d\n", i, ' ', temp->value);
		temp = temp->next;
	}
}