#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

/*int **createTable(int n, int m);
void deleteTable(int **&table, int n, int m);*/

int main()
{
	fstream input("input.txt");

	int n = 0;
	int k = 0;
	input >> n >> k;

	//int **table = createTable(k, n);
	int table[1000][1000];

	for (int j = 1; j <= n; ++j)
	{
		for (int l = 1; l <= k; ++l)
		{
			int i = 0;
			char temp = ' ';
			int e = 0;

			input >> i >> temp >> e;
			table[j - 1][i - 1] = e;
		}
	}

	int state = 1;

	while (true)
	{
		cout << "Enter your command ";
		int command = 0;
		cin >> command;

		if (table[state - 1][command - 1] == -1)
		{
			cout << "Your command is not define" << endl;

			//deleteTable(table, n, k);

			system("pause");
			return 0;
		}

		cout << "Current state: " << table[state - 1][command - 1] << endl;
		state = table[state - 1][command - 1];
	}
}

/*int **createTable(int n, int m)
{
	int **table = new int *[n];

	for (int i = 0; i < n; ++i)
		table[i] = new int[m];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			table[i][j] = 0;

	return table;
}

void deleteTable(int **&table, int n, int m)
{
	for (int i = 0; i < n; ++i)
		delete table[i];

	delete [] table;
}*/