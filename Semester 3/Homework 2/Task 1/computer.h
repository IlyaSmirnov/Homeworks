#pragma once

#include <QTime>

enum OS {Windows = 0, Linux };

class Computer
{
public:
	Computer(OS os, int number);

	void infect();
	double getProbability();
	bool isInfected();
	bool isPossibleToInfect();
	int getNumber();

private:
	int number;
	bool infected;
	OS os;
};
