#include "phoneList.h"

using namespace Phone;
using namespace std;

void PhoneList::addEl(char* name, int number)
{
	PhoneListElement *temp = new PhoneListElement;

	temp->name = new char[255];
	strcpy_s(temp->name, strlen(name) + 1, name);
	temp->number = number;
	
	if (head != nullptr) 
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		temp->next = nullptr;
		head = temp;
	}
}

int PhoneList::findByName(char* name)
{
	PhoneListElement* temp = head;

	while (temp != nullptr)
	{
		if (strcmp(temp->name, name) == 0)
			return temp->number;
		temp = temp->next;
	}
}

char* PhoneList::findByNumber(int number)
{
	PhoneListElement* temp = head;

	while (temp != nullptr)
	{
		if (temp->number == number)
			return temp->name;
		temp = temp->next;
	}
}

void PhoneList::saveInFile(PhoneList* list)
{
	ofstream out("output.txt");
	PhoneListElement* temp = head;

	if (out.is_open())
		while (temp != nullptr)
		{
			out << temp->name << ' ' << temp->number << endl;
			temp = temp->next;
		}
	else
		printf("%s\n", "Your file is not exits");

	out.close();
}