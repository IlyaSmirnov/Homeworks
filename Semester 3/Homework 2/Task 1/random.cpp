#include "random.h"

Random::~Random()
{
}

double Random::getRandom()
{
	return (rand() % 100 + 1) / 100;
}
