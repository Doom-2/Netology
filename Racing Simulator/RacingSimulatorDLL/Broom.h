#pragma once

#include "AirVehicle.h"

class Broom : public AirVehicle
{
public:
	Broom();

	double calcRaceTime(int dist);

};
