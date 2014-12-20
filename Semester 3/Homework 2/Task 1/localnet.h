#pragma once

#include "computer.h"

#include <QList>
#include <iostream>
#include <QVariant>
#include <QCoreApplication>
#include <QEventLoop>

const int maxSizeOfNet = 100;

class LocalNet
{
public:
	LocalNet();
	LocalNet(int numberOfComputers, QList<Computer> computers, int matrix[maxSizeOfNet][maxSizeOfNet], int numberOfInfected);

	void setNetFromConsole();
	void startToCheckSystemState();

private:
	void makeTurn();
	void showCurrentState();

	QList<Computer> computers;
	int matrix[maxSizeOfNet][maxSizeOfNet];
	int numberOfInfected;
};
