#include "unweightedGraph.h"
#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace graph;

int main()
{	
	fstream input("input.txt");

	if (!input.is_open())
	{
		cout << "File input.txt doesn't exist" << endl;
		return 0;
	}

	cout << "Welcome to the program which print connected components of the graph" << endl;

	int n = 0;
	input >> n ;
	
	Graph *graph = new Graph[1000];

	for (int i = 0; i < n; ++i)
		graph[i] = createGraph();

	while (!input.eof())
	{
		int roadEnd1 = 0;
		int roadEnd2 = 0;
			
		input >> roadEnd1 >> roadEnd2;

		addPath(graph[roadEnd1 - 1], roadEnd2 - 1);
		addPath(graph[roadEnd2 - 1], roadEnd1 - 1);
	}

	printGraph(graph, n);

	for (int i = 0; i < n; ++i)
		deleteGraph(graph[i]);

	delete [] graph;
	
	input.close();
	system("PAUSE");

	return 0;
}