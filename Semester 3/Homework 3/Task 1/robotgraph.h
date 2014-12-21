#pragma once

#include <QVector>
#include <QDebug>
#include <QObject>
#include <QtTest/QtTest>

class RobotGraph
{
public:
	RobotGraph(int size, QVector<QVector<bool> > graph, QVector<bool> robots);

	///check if there are opportunity to all robots to self-distruct
	bool check();

private:
	void dfs(int start, int &count);
	QVector<bool> used;

	///adjacency matrix of graph
	QVector<QVector<bool> > graph;
	///positions of robots
	QVector<bool> robots;
	int size;
};
