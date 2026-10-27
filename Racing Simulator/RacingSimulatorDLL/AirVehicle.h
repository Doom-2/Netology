#pragma once

#include "Vehicle.h"

class AirVehicle : public Vehicle
{
public:
	AirVehicle(const std::string& name, int speed, int baseReduction = 0);

	double calcRaceTime(int dist) const override;

protected:
	// distance percentage reduction
	virtual int distReductionPercent(int dist) const;

private:
	int _baseReduction;


};
