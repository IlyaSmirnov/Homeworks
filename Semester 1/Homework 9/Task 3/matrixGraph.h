#pragma once
#include <iostream>

namespace graph
{
	int** createGraph(int size);
	void deleteGraph(int **graph, int size);
	void show(int **graph, int size);
}