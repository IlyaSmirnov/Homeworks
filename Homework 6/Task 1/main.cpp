#include "set.h"

using namespace TreeADT;

int main()
{
	printf_s("%s\n", "Welcome to the program of the set");
	printf_s("%s\n", "Enter the number and then something would happen!");

	printf_s("%s\n", "Enter 0 - exit");
	printf_s("%s\n", "Enter 1 - add a integer number in your set");
	printf_s("%s\n", "Enter 2 - remove a number in your set");
	printf_s("%s\n", "Enter 3 - check the existence of the number in your set");
	printf_s("%s\n", "Enter 4 - print a numbers of your set in ascending order");
	printf_s("%s\n", "Enter 5 - print a numbers of your set in descending order");
	printf_s("%s\n", "Enter 6 - print a numbers of your set in (a b c) format");

	BinaryTree tree = create();
	
	while (true)
	{
		printf("%s", "Enter number: ");

		enum userñChoise { exit = 0, add, remove, existence, ascending, descanding, format };

		userñChoise choise;

		scanf_s("%d", &choise);
	
		int value = 0;

		switch (choise)
		{
			case 0:
			{
				deleteTree(tree);

				return 0;
			}

			case 1:
			{
				printf("%s", "Enter number, which you want to add: ");
				scanf_s("%d", &value);

				addValue(tree, value);

				break;
			}

		case 2:
		{
			printf("%s", "Enter number, which you want to remove: ");
			scanf_s("%d", &value);

			removeValue(tree, value);

			break;
		}

		case 3:
		{
			printf("%s", "Enter number, which you want to check on existence: ");
			scanf_s("%d", &value);

			printf("%s\n", exist(tree, value) ? "Your numer in the set" : "Your numer not in the set");

			break;
		}

		case 4:
		{
			printf("%s\n", "Your set in ascending order:");

			if (tree.root != nullptr)
			{
				printAscennding(tree);
				printf("\n");
			}
			else
				printf("%s\n", "Your set is empty!");

			break;
		}
		case 5:
		{
			printf("%s\n", "Your set in descending order:");

			if (tree.root != nullptr)
			{
				printDescending(tree);
				printf("\n");
			}
			else
				printf("%s\n", "Your set is empty!");

			break;
		}
		case 6:
		{
			printf("%s\n", "Your set in (a b c) format:");

			if (tree.root != nullptr)
			{
				printSomeOrder(tree);
				printf("\n");
			}
			else
				printf("%s\n", "Your set is empty!");

			break;
		}
	}
}
}