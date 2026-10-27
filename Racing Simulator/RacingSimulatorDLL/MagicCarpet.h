#pragma once

#include "AirVehicle.h"

class MagicCarpet : public AirVehicle
{
public:
	MagicCarpet();

protected:
	int distReductionPercent(int dist) const override;
};
