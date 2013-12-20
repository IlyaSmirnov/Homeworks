#include "weightedGraph.h"

#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;
using namespace graph;

void dijkstra(GraphVertex *graph, int n)
{
	bool visited[1000];
	int shortestPath[1000];
	int shortestDistation[1000];
	int previous[1000];

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		previous[i] = 0;
		shortestDistation[i] = 1000000;
	}

	visited[0] = true;
	shortestDistation[0] = 0;
	
	while (true)
	{
		int minVertex = -1;

		for (int i = 0; i < n; ++i)
			if ((visited[i]) && ((minVertex == -1) || shortestDistation[i] < shortestDistation[minVertex]))
				minVertex = i;
		
		if (minVertex == -1)
			break;

		if (minVertex != 0)
		{
			cout << "Number of town: " << minVertex + 1 << " Distation from town 1: " << shortestDistation[minVertex];

			int counter = 0;
			int j = minVertex;

			while (j != 0)
			{
				counter++;
				shortestPath[counter] = j;
				j = previous[j];
			}

			++counter;
			shortestPath[counter] = 0;

			cout << " PATH: ";
			for (int i = counter; i > 0; --i)
				cout << shortestPath[i] + 1 << ' ';

			cout << endl;
		}
	
		Path *temp = graph[minVertex].head;

		for (int i = 1; i <= numberOfNeighbour(graph[minVertex]); ++i)
		{
			if (shortestDistation[temp->vertex] > shortestDistation[minVertex] + temp->weight)
			{
				shortestDistation[temp->vertex] = shortestDistation[minVertex] + temp->weight;
				previous[temp->vertex] = minVertex;
				visited[temp->vertex] = true;
			}
			
			temp = temp->next;
		}

		visited[minVertex] = false;
		}

	return;
}

int main()
{
	fstream input("input.txt");

	if (!input.is_open())
		cout << "File input.txt doesn't exist" << endl;
	else
	{
		cout << "Welcome to the program which will tell you when Nazis will come to your town" << endl;

		int n = 0;
		int m = 0;
		input >> n >> m;

		GraphVertex graph[10];

		for (int i = 0; i < n; ++i)
			graph[i] = createGraph();
		
		while (!input.eof())
		{
			int roadEnd1 = 0;
			int roadEnd2 = 0;
			int len = 0;

			input >> roadEnd1 >> roadEnd2 >> len;

			addPath(graph[roadEnd1 - 1], roadEnd2 - 1, len);
			addPath(graph[roadEnd2 - 1], roadEnd1 - 1, len);
		}

		dijkstra(graph, n);

		for (int i = 0; i < n; ++i)
			deleteGraphVertex(graph[i]);
	}

	input.close();
	system("PAUSE");

	return 0;
}