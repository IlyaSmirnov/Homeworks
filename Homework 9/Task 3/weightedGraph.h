#pragma once

namespace graph
{
	struct Path
	{
		int vertex;
		int weight;
		Path *next;
	};

	struct Graph
	{
		Path *head;
		int size;
		bool visit;
	};

	Graph createGraph();
	void deleteGraph(Graph &graph);

	void addPath(Graph &graph, int vertex, int weight);
}