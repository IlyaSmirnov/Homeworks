#include "weightedGraph.h"

using namespace graph;
using namespace std;

Graph graph::createGraph()
{
	Graph graph;
	graph.head = nullptr;
	graph.visit = false;
	graph.size = 0;

	return graph;
}

void graph::deleteGraph(Graph &graph)
{
	while (graph.head != nullptr)
	{
		Path *temp = graph.head->next;
		delete graph.head;
		graph.head = temp;
	}

	return;
}

void graph::addPath(Graph &graph, int vertex, int weight)
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