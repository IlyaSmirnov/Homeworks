#include "matrixGraph.h"

using namespace graph;
using namespace std;

int** graph::createGraph(int size)
{
	int **graph = new int *[size];

	for (int i = 0; i < size; ++i)
		graph[i] = new int[size];
	
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			graph[i][j] = 0;

	return graph;
}

void graph::deleteGraph(int **graph, int size)
{
	for (int i = 0; i < size; ++i)
		delete [] graph[i];

	delete[] graph;

	return;
}

void graph::show(int **graph, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << graph[i][j] << " ";

		cout << "\n";
	}

	return;
}