#pragma once

namespace graph
{
	struct Path
	{
		int vertex1;
		int vertex2;
		int weight;
		Path *next;
	};

	struct Graph
	{
		Path *head;
		int size;
	};

	Graph* createGraph(int n, int m);
	void deleteGraph(Graph *&graph);

	void addPath(Graph *&graph, int vertex1, int vertex2, int weight);
}