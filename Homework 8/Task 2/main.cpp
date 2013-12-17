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

	for (int i = 1; i <= n; ++i)
	{
		visited[i] = false;
		previous[i] = 0;
		shortestDistation[i] = 1000000;
	}

	visited[1] = true;
	shortestDistation[1] = 0;
	
	while (true)
	{
		int minVertex = 0;

		for (int i = 1; i <= n; ++i)
		if ((visited[i]) && ((minVertex == 0) || shortestDistation[i] < shortestDistation[minVertex]))
			minVertex = i;
		
		if (minVertex == 0)
			break;

		if (minVertex != 1)
		{
			cout << "Number of town: " << minVertex << " Distation from town 1: " << shortestDistation[minVertex];

			int counter = 1;
			int j = minVertex;

			while (j != 1)
			{
				shortestPath[counter] = j;
				counter++;
				j = previous[j];
			}

			shortestPath[counter] = 1;
			printf("%s", " PATH: ");
			for (int i = counter; i >= 1; --i)
				cout << shortestPath[i] << ' ';

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
	cout << "Welcome to the program which will tell you when Nazis will come to your town" << endl;
	
	fstream input("input.txt");

	if (!input.is_open())
		cout << "File input.txt doesn't exist" << endl;
	else
	{
		int n = 0;
		int m = 0;
		input >> n >> m;

		GraphVertex graph[10];

		for (int i = 1; i <= n; ++i)
			graph[i] = createGraph();
		
		while (!input.eof())
		{
			int roadEnd1 = 0;
			int roadEnd2 = 0;
			int len = 0;

			input >> roadEnd1 >> roadEnd2 >> len;

			addPath(graph[roadEnd1], roadEnd2, len);
			addPath(graph[roadEnd2], roadEnd1, len);
		}

		dijkstra(graph, n);

		for (int i = 1; i <= n; ++i)
			deleteGraphVertex(graph[i]);
	}

	input.close();
	system("PAUSE");

	return 0;
}