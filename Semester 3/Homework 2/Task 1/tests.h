#pragma once

#include <QtTest/QtTest>
#include "localnet.h"

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}

private slots:

	void check()
	{
		QList<Computer> computers;
		computers.append(Computer((OS)0, 0));
		computers.append(Computer((OS)1, 1));
		computers.append(Computer((OS)0, 2));
		computers.append(Computer((OS)0, 3));

		int numberOfComputers = 4;
		int matrix[maxSizeOfNet][maxSizeOfNet];

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

		LocalNet net(numberOfComputers, computers, matrix, numberOfInfected);
		net.startToCheckSystemState();
	}
};
