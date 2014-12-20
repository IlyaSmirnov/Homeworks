#pragma once

#include "computer.h"

#include <QList>
#include <iostream>
#include <QVariant>
#include <QCoreApplication>
#include <QEventLoop>

const int maxSizeOfNet = 100;

///simulation of local network
class LocalNet
{
public:
	LocalNet();
	LocalNet(int numberOfComputers, QList<Computer> computers, int matrix[maxSizeOfNet][maxSizeOfNet], int numberOfInfected);

	///set settings of the net from console
	void setNetFromConsole();
	///show state of the net every 3 seconds
	void startToCheckNetState();

private:
	///try to infect other computer
	void makeTurn();
	///show which computers infected now
	void showCurrentState();

	///list of computers in network
	QList<Computer> computers;
	///matrix of connections between computers
	int matrix[maxSizeOfNet][maxSizeOfNet];
	///number of infected computers
	int numberOfInfected;
};
