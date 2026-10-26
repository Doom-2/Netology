#pragma once

#include "GroundVehicle.h"

class SuperBoots : public GroundVehicle
{
public:
	SuperBoots();

	double calcRaceTime(int dist);
};
