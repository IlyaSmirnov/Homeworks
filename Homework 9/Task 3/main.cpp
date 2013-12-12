#include "matrixGraph.h"
#include <fstream>

using namespace std;
using namespace graph;

int **prim(int **graph, int size)
{
	int **spanningTree = createGraph(size);

	bool visited[100000];
	int minWeights[100000];
	int minVerrtexs[100000];
	
	for (int i = 0; i < size; ++i)
	{
		visited[i] = false;
		minWeights[i] = 100000;
		minVerrtexs[i] = -1;
	}

	int current = 0;

	while (true)
	{
		visited[current] = true;

		int minVertex = -1;
		int minWeight = 1000000000;

		for (int i = 0; i < size; ++i)
			if (!visited[i])
			{
				if ((graph[i][current] < minWeights[i]) && (graph[i][current] != 0))
				{
					minWeights[i] = graph[current][i];
					minVerrtexs[i] = current;
				}

				if (minWeights[i] < minWeight)
				{
					minWeight = minWeights[i];
					minVertex = i;
				}
			}
		
		if (minVertex != -1)
		{
			spanningTree[minVerrtexs[minVertex]][minVertex] = minWeights[minVertex];
			spanningTree[minVertex][minVerrtexs[minVertex]] = minWeights[minVertex];

			current = minVertex;
		}
		else
			return spanningTree;
	}
}

int main()
{
	cout << "Welcome to the program of the Prim's algorithm" << endl;

	fstream input("input.txt");

	if (!input.is_open())
		cout << "File with this name doesn't exist" << endl;
	else
	{
		int size = 0;
		input >> size;

		int **graph = createGraph(size);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
					input >> graph[i][j];

		int **spanningTree = prim(graph, size);

		show(spanningTree, size);

		deleteGraph(graph, size);
		deleteGraph(spanningTree, size);
	}

	input.close();
	system("PAUSE");

	return 0;
}