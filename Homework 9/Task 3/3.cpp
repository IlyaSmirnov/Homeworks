#include "matrixGraph.h"
#include "List.h"
#include <fstream>

using namespace std;
using namespace list;
using namespace graph;

int main()
{
	cout << "Welcome to the program of the Prim's algorithm" << endl;
	
	fstream input("input.txt");

	if (!input.is_open())
		cout << "File with this name doesn't exist" << endl;
	else
	{
		int **edges = createGraph();

		while (!input.eof())
		{
			int weight = 0;

			input >> weight;

			addGraphElement(we);
		}

		Graph vertex[10000];
		vertex[1] = graph[1];

		path
		while (temp != nuulptr)

		for (int i = 1; i <= n; ++i)
			deleteGraph(graph[i]);
	}

	input.close();
	system("PAUSE");

	return 0;
}