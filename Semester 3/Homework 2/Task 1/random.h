#pragma once

#include "generator.h"
#include <algorithm>

class Random : public Generator
{
public:
	~Random();

	double getRandom();
};
