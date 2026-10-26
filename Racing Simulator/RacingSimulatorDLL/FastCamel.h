#pragma once

#include "GroundVehicle.h"

class FastCamel : public GroundVehicle
{
public:
	FastCamel();

	double calcRaceTime(int dist);
};
