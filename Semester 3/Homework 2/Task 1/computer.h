#pragma once

#include <QTime>

///Computer
class Computer
{
public:
	Computer(int number);
	virtual ~Computer();

	///infect computer by virus
	void infect();
	///get probability if getting infected according the type of OS
	double getProbability();
	bool isInfected();
	///return number of computer in net
	int getNumber();

protected:
	int number;
	///probability of getting infected according OS
	double probability;
	bool infected;
};
