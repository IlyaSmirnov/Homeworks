#pragma once

#include "generator.h"

class AlmostRandom : public Generator
{
public:
	~AlmostRandom();

	double getRandom();
};
