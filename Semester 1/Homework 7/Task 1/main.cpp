#include <stdlib.h>
#include <iostream>

using namespace std;

int  findTheBlame(int * ones, int &number)
{
	if (ones[number] >= 4)
	{
		return findTheBlame(ones, number);
	}
	else
	{
		return ones[number];
	}
}

int main()
{
	cout << "Welcome to the program which would help you to expel students" << endl;
	
	cout << "Enter the amount of students: ";
	int amount = 0;
	cin >> amount;

	cout << "Enter the number of student and the one who help him. If you want to stop it, enter stop" << endl;
	
	int ones[10000];
	int number = 6;
	int one = 0;

	for (int i = 1; i <= amount; ++i)
	{
		ones[i] = 0;
	}

	while ((cin >> number) && (number != 0) && (cin >> one)) 
		ones[number] = one;

	bool check;

	while (true)
	{
		check = true;
		for (int i = 4; i <= amount; i++)
		{
			if (ones[i] >= 4)
			{
				ones[i] = findTheBlame(ones, ones[i]);
				if (ones[i] >= 4)
					check = false;
			}
		}
		if (check)
			break;
	}

	for (int i = 1; i <= 3; i++)
	cout << i << ' ' << "This guy is smart" << endl;

	for (int i = 4; i <= amount; i++)
		if (ones[i] != 0)
			cout << i << ' ' << ones[i] << endl;
		else
			cout << i << ' ' << "THIS STUDENT MUST BE EXPELLED!" << endl;

	system("PAUSE");

	return 0;
}