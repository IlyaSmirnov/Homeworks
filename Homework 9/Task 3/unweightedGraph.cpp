#include "unweightedGraph.h"
#include "list.h"

using namespace graph;
using namespace list;
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

	cout << i << ' ';
	
	visited[i] = true;

	while (temp != nullptr)
	{
		if (!visited[temp->vertex])
			DFS(graph, temp->vertex, visited);

		temp = temp->next;
	}

	return;
}

bool check(Graph graph[], bool *&visited)
{
	for (int i = 1; i <= graph->size; ++i)
		if (!visited[i])
		{
			return false;
		}

	return true;
}

void graph::printGraph(Graph *&graph)
{
	int number = 0;

	bool *visited = new bool[10000];

	for (int i = 1; i <= graph->size; ++i)
		visited[i] = false;

	while (!check(graph, visited))
	{
		for (int i = 1; i <= graph->size; ++i)
		{
			if (!visited[i])
			{
				++number;
				cout << "Number of the component: " << number << " List of elements: ";
				DFS(graph, i, visited);
				cout << endl;
				break;
			}
		}
	}
	return;
}