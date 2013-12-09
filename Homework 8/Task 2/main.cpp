#include "weightedGraph.h"
#include "list.h"

#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace graph;
using namespace list;

bool check(Graph *graph, bool *&visitedDijkstra)
{
	Path *temp = graph->head;
	while (temp != nullptr)
	{
		if ((!visitedDijkstra[temp->vertex1]) || ((!visitedDijkstra[temp->vertex2])))
			return false;

		temp = temp->next;
	}

	return true;
}

void dijkstra(Graph *&graph, int number, List *&shortestPathes, bool visitedDijkstra[10000], int shortestDistations[10000])
{
	Path *temp = graph->head;
	int minVertex = 0;
	int minLen = 1000000000;
	visitedDijkstra[number] = true;

	while (temp != nullptr)
		{
			if (temp->vertex1 == number)
			{
				if (shortestDistations[temp->vertex2] > temp->weight)
				{
					shortestDistations[temp->vertex2] = shortestDistations[number] + temp->weight;
					deleteList(shortestPathes[temp->vertex2]);
					shortestPathes[temp->vertex2] = createList();
					shortestPathes[temp->vertex2] = shortestPathes[number];
					addElement(shortestPathes[temp->vertex2], temp->vertex2);

					if ((shortestDistations[temp->vertex2] < minLen) && (!visitedDijkstra[temp->vertex2]))
					{
						minVertex = temp->vertex2;
						minLen = shortestDistations[temp->vertex2];
					}
				}
			}

			if (temp->vertex2 == number)
			{
				if (shortestDistations[temp->vertex1] > temp->weight)
				{
					shortestDistations[temp->vertex1] = shortestDistations[number] + temp->weight;
					deleteList(shortestPathes[temp->vertex1]);
					shortestPathes[temp->vertex1] = createList();
					shortestPathes[temp->vertex1] = shortestPathes[number];
					addElement(shortestPathes[temp->vertex1], temp->vertex2);
				}

				if ((shortestDistations[temp->vertex1] < minLen) && (!visitedDijkstra[temp->vertex1]))
				{
					minVertex = temp->vertex1;
					minLen = shortestDistations[temp->vertex1];
				}
			}

			temp = temp->next;
	}

	if (!check(graph, visitedDijkstra))
		dijkstra(graph, minVertex, shortestPathes, visitedDijkstra, shortestDistations);
	

	return;
}

void startDijkstra(Graph *&graph, int number, int &distation, List &conquered, bool *&visited, int minLen, int minVertex)
{
	bool visitedDijkstra[100000];
	List *shortestPathes = new List[graph->size];
	int shortestDistations[100000];

	for (int i = 1; i <= graph->size; ++i)
	{
		shortestPathes[i] = createList();
		visitedDijkstra[i] = false;
		shortestDistations[i] = 1000000000;
	}

	visitedDijkstra[0] = true;
	visitedDijkstra[number] = true;
	shortestDistations[number] = 0;

	dijkstra(graph, number, shortestPathes, visitedDijkstra, shortestDistations);

	for (int i = 1; i <= graph->size; ++i)
	{
		if (!visited[i])
		{
			if (minVertex == -1)
			{
				minVertex = i;
				minLen = shortestDistations[i];

				continue;
			}

			if (minLen > shortestDistations[i])
			{
				minVertex = i;
				minLen = shortestDistations[i];
			}

		}
	}

	ListElement *temp = shortestPathes[minVertex].head;
	while (temp != nullptr)
	{
		addElement(conquered, temp->value);

		temp = temp->next;
	}

	return;
}

void conquer(Graph *&graph, int number, int &distation, List &conquered, bool visited[10000])
{
	Path *temp = graph->head;
	
	visited[number] = true;

	int minVertex = -1;
	int minLen = 0;

	while (temp != nullptr)
	{
		if ((temp->vertex1 == number) && (!visited[temp->vertex2]))
		{
			if (minVertex == -1)
			{
				minVertex = temp->vertex2;
				minLen = temp->weight;

				continue;
			}

			if (minLen > temp->weight)
			{
				minVertex = temp->vertex2;
				minLen = temp->weight;
			}
		}

		if ((temp->vertex2 == number) && (!visited[temp->vertex1]))
		{
			if (minVertex == -1)
			{
				minVertex = temp->vertex1;
				minLen = temp->weight;

				continue;
			}

			if (minLen > temp->weight)
			{
				minVertex = temp->vertex1;
				minLen = temp->weight;
			}
		}

		temp = temp->next;
	}

	if (minVertex == -1)
		startDijkstra(graph, number, distation, conquered, visited, minLen, minVertex);

	if (minVertex != -1)
	{
		distation += minLen;	
		cout << "Number of town: " << minVertex << " Distation from town 1: " << distation;
		show(conquered);
		addElement(conquered, minVertex);
		conquer(graph, minVertex, distation, conquered, visited);
	}
	else
		return;
	
	return;

}

void starConquer(Graph *&graph)
{
	List conquered = createList();
	int distation = 0;

	bool visited[100000];
	for (int i = 1; i <= graph->size; ++i)
		visited[i] = false;

	visited[1] = true;

	conquer(graph, 1, distation, conquered, visited);
}


int main()
{
	cout << "Welcome to the program which will tell you when Nazis will come to your town" << endl;
	
	fstream input("input.txt");

	if (!input.is_open())
		cout << "File input.txt doesn't exist" << endl;
	else
	{
		int n = 0;
		int m = 0;
		input >> n >> m;


		Graph *graph = createGraph(n, m);
		graph->size = n;


		while (!input.eof())
		{
			int roadEnd1 = 0;
			int roadEnd2 = 0;
			int len = 0;

			input >> roadEnd1 >> roadEnd2 >> len;

			addPath(graph, roadEnd1, roadEnd2, len);
		}

		starConquer(graph);
	}

	input.close();
	system("PAUSE");

	return 0;
}