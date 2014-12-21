#pragma once


#include "robotgraph.h"

class rTest : public QObject
{
	Q_OBJECT
public:
	explicit rTest(QObject *parent = 0) {}

private slots:
	void trueTest()
	{
		QVector<QVector<bool> > graph = {{false, true, false, false},
										 {true, false, true, false},
										 {false, true, false, true},
										 {false, false, true, false}};
		QVector<bool> robots = {true, false, true, false};

		RobotGraph robotgraph(4, graph, robots);
		QVERIFY(robotgraph.check());
	}

	void falseTest()
	{
		QVector<QVector<bool> > graph = {{false, true, false, false},
										 {true, false, true, false},
										 {false, true, false, true},
										 {false, false, true, false}};
		QVector<bool> robots = {true, false, false, true};

		RobotGraph robotgraph(4, graph, robots);
		QVERIFY(!robotgraph.check());
	}
};
