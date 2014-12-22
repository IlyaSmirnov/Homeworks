#include "computer.h"

Computer::Computer(int number) : infected(false)
{
	this->number = number;
}

Computer::~Computer()
{
}

void Computer::infect()
{
	infected = true;
}

double Computer::getProbability()
{
	return probability;
}

bool Computer::isInfected()
{
	return infected;
}

int Computer::getNumber()
{
	return number;
}
