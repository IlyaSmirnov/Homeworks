#pragma once

#include <QtTest/QtTest>
#include "localnet.h"

class Tests : public QObject {
	Q_OBJECT
public:
	explicit Tests(QObject *parent = 0) : QObject(parent) {}
	
private slots:
	
	void randomTest()
	{
		Random *random = new Random;

		QList<Computer> computers;
		computers.append(Computer(0));
		computers.append(Computer(1));
		computers.append(Computer(2));
		computers.append(Computer(3));

		int numberOfComputers = 4;
		QVector<QVector<int> > matrix;

		matrix.resize(numberOfComputers);
		for (int i = 0; i < numberOfComputers; ++i)
			matrix[i].resize(numberOfComputers);

		matrix[0][0] = 0;
		matrix[0][1] = 0;
		matrix[0][2] = 0;
		matrix[0][3] = 0;
		matrix[1][0] = 0;
		matrix[1][1] = 0;
		matrix[1][2] = 0;
		matrix[1][3] = 0;
		matrix[2][0] = 0;
		matrix[2][1] = 0;
		matrix[2][2] = 0;
		matrix[2][3] = 0;
		matrix[3][0] = 0;
		matrix[3][1] = 0;
		matrix[3][2] = 0;
		matrix[3][3] = 0;

		int numberOfInfected = 0;

		LocalNet *net = new LocalNet(numberOfComputers, computers, matrix, numberOfInfected, random);
		net->makeTurn();

		QVERIFY(net->getNumberOfInfected() == 1);
	}

	void AlmostRandomTest()
	{
		AlmostRandom *random = new AlmostRandom;

		QList<Computer> computers;
		computers.append(Computer(0));
		computers.append(Computer(1));
		computers.append(Computer(2));
		computers.append(Computer(3));

		int numberOfComputers = 4;
		QVector<QVector<int> > matrix;

		matrix.resize(numberOfComputers);
		for (int i = 0; i < numberOfComputers; ++i)
			matrix[i].resize(numberOfComputers);

		matrix[0][0] = 0;
		matrix[0][1] = 1;
		matrix[0][2] = 1;
		matrix[0][3] = 0;
		matrix[1][0] = 1;
		matrix[1][1] = 0;
		matrix[1][2] = 0;
		matrix[1][3] = 1;
		matrix[2][0] = 1;
		matrix[2][1] = 0;
		matrix[2][2] = 0;
		matrix[2][3] = 0;
		matrix[3][0] = 0;
		matrix[3][1] = 1;
		matrix[3][2] = 0;
		matrix[3][3] = 0;

		int numberOfInfected = 0;

		LocalNet *net = new LocalNet(numberOfComputers, computers, matrix, numberOfInfected, random);
		net->makeTurn();
		net->makeTurn();
		net->makeTurn();

		QVERIFY(net->getNumberOfInfected() == 4);

		delete random;
		delete net;
	}
};
