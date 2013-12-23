#include "weightedGraph.h"

using namespace graph;
using namespace std;

GraphVertex graph::createGraph()
{
	GraphVertex graph;
	graph.head = nullptr;

	return graph;
}

void graph::deleteGraphVertex(GraphVertex &graph)
{
	while (graph.head != nullptr)
	{
		Path *temp = graph.head->next;
		delete graph.head;
		graph.head = temp;
	}

	return;
}

void graph::addPath(GraphVertex &graph, int vertex, int weight)
{
	Path *temp = new Path;
	temp->vertex = vertex;
	temp->weight = weight;

	if (graph.head != nullptr)
	{
		temp->next = graph.head;
		graph.head = temp;
	}
	else
	{
		temp->next = nullptr;
		graph.head = temp;
	}

	return;
}

int graph::numberOfNeighbour(GraphVertex graph)
{
	Path *temp = graph.head;

	int result = 0;

	while (temp != nullptr)
	{
		temp = temp->next;
		++result;
	}

	return result;
}