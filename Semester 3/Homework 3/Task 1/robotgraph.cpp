#include "robotgraph.h"

RobotGraph::RobotGraph(int size, QVector<QVector<bool> > graph, QVector<bool> robots)
{
	this->size = size;
	this->graph = graph;
	this->robots = robots;

	used.resize(size);
	for (int i = 0; i < size; ++i)
		used[i] = false;
}

bool RobotGraph::check()
{
	if (size < 2)
		return false;

	for (int i = 0; i < size; ++i)
		if (!used[i] && robots[i])
		{
			int count = 0;
			dfs(i, count);
			if (count == 1)
				return false;
		}

	return true;
}

void RobotGraph::dfs(int start, int &count)
{
	if (used[start])
		return;

	if (robots[start])
		++count;

	used[start] = true;

	for (int i = 0; i < size; ++i)
		if (graph[start][i] && !used[i])
			for (int j = 0; j < size; ++j)
				if (graph[i][j])
					dfs(j, count);
}
