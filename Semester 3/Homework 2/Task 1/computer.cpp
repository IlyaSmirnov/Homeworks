#include "computer.h"

Computer::Computer(OS os, int number) : infected(false)
{
	this->os = os;
	this->number = number;
}

void Computer::infect()
{
	infected = true;
}

double Computer::getProbability()
{
	if (os == 0)
		return 0.4;
	else
		return 0.2;
}

bool Computer::isInfected()
{
	return infected;
}

bool Computer::isPossibleToInfect()
{
	double random = (double)(rand() % 100) / 100;
	if (random < getProbability())
		return true;

	return false;
}

int Computer::getNumber()
{
	return number;
}
