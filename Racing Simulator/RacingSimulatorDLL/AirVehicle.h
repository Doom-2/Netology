#pragma once

#include "Vehicle.h"

class AirVehicle : public Vehicle
{
protected:
	int _distReductionFactor{};

	// distance percentage reduction
	virtual int distReductionPercent(int dist) const;

public:
	AirVehicle(const std::string& name, const int& speed);

	double calcRaceTime(int dist) const;
};
