#pragma once

namespace graph
{
	struct Path
	{
		int vertex;
		int weight;
		Path *next;
	};

	struct GraphVertex
	{
		Path *head;
	};

	GraphVertex createGraph();
	void deleteGraphVertex(GraphVertex &graph);

	void addPath(GraphVertex &graph, int vertex, int weight);
	int numberOfNeighbour(GraphVertex graph);
}