#pragma once

#include "windowscomputer.h"
#include "linuxcomputer.h"
#include "random.h"
#include "almostrandom.h"

#include <QList>
#include <iostream>
#include <QVariant>
#include <QCoreApplication>
#include <QEventLoop>
#include <QVector>
#include <QObject>
#include <QTimer>

///simulation of local network
class LocalNet : public QObject
{
	Q_OBJECT
public:
	LocalNet();
	LocalNet(int numberOfComputers, QList<Computer> computers, QVector<QVector<int> > matrix, int numberOfInfected, Generator *generator);

	///set settings of the net from console
	void setNetFromConsole();
	///show state of the net every 3 seconds
	void startToCheckNetState();
	///show which computers infected now
	void showCurrentState();

	int getNumberOfInfected();

public slots:
	///try to infect other computer
	void makeTurn();

private:
	///return true if there are any opportunity of getting infected
	bool isPossibleToInfect(Computer computer);
	///list of computers in network
	QList<Computer> computers;
	///matrix of connections between computers
	QVector<QVector<int> > matrix;
	///number of infected computers
	int numberOfInfected;
	QTimer timer;
	Generator *generator;
};
