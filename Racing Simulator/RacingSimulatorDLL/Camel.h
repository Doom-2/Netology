#pragma once

#include "GroundVehicle.h"

class Camel : public GroundVehicle
{
public:
	Camel();

	double calcRaceTime(int dist);
};
