#pragma once

#include "GroundVehicle.h"

class Centaur : public GroundVehicle
{
public:
	Centaur();

	double calcRaceTime(int dist);

};
