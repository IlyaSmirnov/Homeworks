#include "weightedGraph.h"
#include "List.h"
#include <fstream>

using namespace std;
using namespace list;
using namespace graph;

void ()

int main()
{
	cout << "Welcome to the program of the Prim's algorithm" << endl;
	
	fstream input("input.txt");

	if (!input.is_open())
		cout << "File with this name doesn't exist" << endl;
	else
	{
		int n = 0;
		input >> n;

		Graph graph[1000];
		Graph Pathes;
		graph->size = 0;
		
		for (int i = 1; i <= n; i++)
		{
			graph[i] = createGraph();
		}

		Graph spanningTree[1000];
		List unVisitedVertex = createList();

		for (int i = 1; i <= n; ++i)
		{
			spanningTree[i] = createGraph();
			graph[i] = createGraph();
		}

		while (!input.eof())
		{
			int temp1 = 0;
			int temp2 = 0;
			int len = 0;

			input >> temp1 >> temp2 >> len;

			addElement(unVisitedVertex, temp1);
			addElement(unVisitedVertex, temp2);

			addPath(graph[temp1], temp2, len);
			addPath(graph[temp2], temp1, len);
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