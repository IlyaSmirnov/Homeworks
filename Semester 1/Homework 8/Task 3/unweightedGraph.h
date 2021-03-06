#pragma once
#include "iostream"

namespace graph
{
	struct Path
	{
		int vertex;
		Path *next;
	};

	struct Graph
	{
		Path *head;
	};

	Graph createGraph();
	void deleteGraph(Graph &graph);

	void addPath(Graph &graph, int vertex);
	void printGraph(Graph *graph, int size);
}