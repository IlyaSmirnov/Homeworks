#include "unweightedGraph.h"
#include <fstream>

using namespace std;
using namespace list;

int main()
{
	cout << "Welcome to the program which numerate your graph" << endl;
	cout << "Enter the name of the file which contains your graph: ";

	int stingLength = 255;
	char *fileName = new char[stingLength];
	int start = 0;

	cin >> fileName;
	cout << "Enter the number of first vertex: ";
	cin >> start;

	fstream input(fileName);

	delete fileName;

	if (!input.is_open())
		cout << "File with this name doesn't exist" << endl;
	else
	{
		int n = 0;
		input >> n;

		List graph[1000];

		for (int i = 1; i <= n; ++i)
			graph[i] = create();
	
		while (!input.eof())
		{
			int temp1 = 0;
			int temp2 = 0;

			input >> temp1 >> temp2;

			addEl(graph[temp1], temp2);
			addEl(graph[temp2], temp1);
		}
	
		DFS(graph, start, 0);

		for (int i = 1; i <= n; ++i)
			deleteList(graph[i]);
	}

	input.close();
	system("PAUSE");

	return 0;
}