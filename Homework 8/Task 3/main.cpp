#include "unWeightedGraph.h"
#include "conquer.h"
#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace graph;

int main()
{
	cout << "Welcome to the program which will tell you when Nazis will come to your town" << endl;
	
	fstream input("input.txt");

	if (!input.is_open())
		cout << "File input.txt doesn't exist" << endl;
	else
	{
		int n = 0;
		input >> n ;

		Graph *graph = new Graph[1000];
		graph->size = n;

		for (int i = 1; i <= n; ++i)
			graph[i] = createGraph();

		while (!input.eof())
		{
			int roadEnd1 = 0;
			int roadEnd2 = 0;
			int len = 0;

			input >> roadEnd1 >> roadEnd2;

			addPath(graph[roadEnd1], roadEnd2);
			addPath(graph[roadEnd2], roadEnd1);
		}

		printGraph(graph);
	}

	input.close();
	system("PAUSE");

	return 0;
}