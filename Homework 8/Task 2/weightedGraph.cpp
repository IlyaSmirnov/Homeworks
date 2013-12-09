#include "weightedGraph.h"

using namespace graph;
using namespace std;

Graph *graph::createGraph(int n, int m)
{
	Graph *graph = new Graph[m];
	graph->head = nullptr;
	graph->size = n;
	
	return graph;
}

void graph::deleteGraph(Graph *&graph)
{
	while (graph->head != nullptr)
	{
		Path *temp = graph->head->next;
		delete graph->head;
		graph->head = temp;
	}

	return;
}

void graph::addPath(Graph *&graph, int vertex1, int vertex2, int weight)
{
	Path *temp = new Path;
	temp->vertex1 = vertex1;
	temp->vertex2 = vertex2;
	temp->weight = weight;
	
	if (graph->head != nullptr)
	{
		temp->next = graph->head;
		graph->head = temp;
	}
	else
	{
		temp->next = nullptr;
		graph->head = temp;
	}

	return;
}