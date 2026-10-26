#pragma once

#include "AirVehicle.h"

class MagicCarpet : public AirVehicle
{
public:
	MagicCarpet();

	double calcRaceTime(int dist);
};
