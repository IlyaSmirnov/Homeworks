#include "phoneList.h"

using namespace Phone;
using namespace std;

int main()
{
	printf_s("%s\n", "Welcome to the program of the phone list");
	printf_s("%s\n", "Enter the number and then something would happen!");
	printf_s("%s\n", "Enter 0 - exit");
	printf_s("%s\n", "Enter 1 - add a note to your phone list");
	printf_s("%s\n", "Enter 2 - find a note in your phome list by name");
	printf_s("%s\n", "Enter 3 - find a note in your phome list by number");
	printf_s("%s\n", "Enter 4 - save your current data in file");

	const int stringLength = 255;

	int n = 5;
	PhoneList *list = new PhoneList;
	int number = 0;
	char* name = new char[stringLength];

	while (true)
	{
		printf("%s", "Enter number: ");
		scanf_s("%d", &n);
		switch (n)
		{
			case 0:
			{
				delete list;
				delete [] name;
				return 0;
			}

			case 1:
			{
				printf("%s", "Enter name of your note: ");

				int i = 0;

				name[0] = getchar();
				while (true)
				{
					name[i] = getchar();

					if (name[i] == '\n')
					{
						name[i] = '\0';
						break;
					}

					i++;
				}
				
				printf("%s", "Enter number of your note: ");
				scanf_s("%d", &number);

				list->addEl(name, number);

				break;
			}

			case 2:
			{
				printf("%s", "Enter name of the note which you want to find: ");

				int i = 0;
	
				name[0] = getchar();
				while (true)
				{
					name[i] = getchar();

					if (name[i] == '\n')
					{
						name[i] = '\0';
						break;
					}

					i++;
				}

				printf("%s%d\n", "Number of the note which you wanted to find: ", list->findByName(name));
				break;
			}

			case 3:
			{
				printf("%s", "Enter number of the note which you want to find: ");
				scanf_s("%d", &number);
				printf("%s%s\n", "Number of the note which you wanted to find: ", list->findByNumber(number));
				
				break;
			}

			case 4:
			{
				list->saveInFile(list);
				break;
			}
		}
	}
	
	system("PAUSE");
	return 0;
}