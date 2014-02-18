#include "unweightedGraph.h"

using namespace graph;
using namespace std;

Graph graph::createGraph()
{
	Graph graph;
	graph.head = nullptr;

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

void graph::addPath(Graph &graph, int vertex)
{
	Path *temp = new Path;
	temp->vertex = vertex;

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

void DFS(Graph *&graph, int i, bool *&visited)
{
	Path *temp = graph[i].head;

	cout << i + 1 << ' ';

	visited[i] = true;

	while (temp != nullptr)
	{
		if (!visited[temp->vertex])
			DFS(graph, temp->vertex, visited);

		temp = temp->next;
	}

	return;
}

bool check(Graph graph[], bool *&visited, int size)
{
	for (int i = 0; i < size; ++i)
		if (!visited[i])
			return false;
	
	return true;
}

void graph::printGraph(Graph *graph, int size)
{
	int number = 0;

	bool *visited = new bool[10000];

	for (int i = 0; i < size; ++i)
		visited[i] = false;

	while (!check(graph, visited, size))
		for (int i = 0; i < size; ++i)
			if (!visited[i])
			{
				++number;
				cout << "Number of the component: " << number << " List of elements: ";
				DFS(graph, i, visited);
				cout << endl;
				break;
			}

	delete [] visited;

	return;
}