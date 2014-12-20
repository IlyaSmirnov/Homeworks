#pragma once

#include <QTime>

///Types of OS
enum OS {Windows = 0, Linux };

///Computer
class Computer
{
public:
	Computer(OS os, int number);

	///infect computer by virus
	void infect();
	///get probability if getting infected according the type of OS
	double getProbability();
	bool isInfected();
	///return true if there are any opportunity of getting infected
	bool isPossibleToInfect();
	///return number of computer in net
	int getNumber();

private:
	int number;
	bool infected;
	OS os;
};
