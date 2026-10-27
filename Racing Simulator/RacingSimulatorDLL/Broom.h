#pragma once

#include "AirVehicle.h"

class Broom : public AirVehicle
{
public:
	Broom();

protected:
	int distReductionPercent(int dist) const override;
};
