#pragma once

#include <vector>
#include "Vehicle.h"

class GroundVehicle : public Vehicle
{
public:
	GroundVehicle(const std::string& name, int speed, int moveTime, std::vector<double> restTimes);

	double calcRaceTime(int dist) const override;

protected:
	int calcRestCount(int dist) const;

private:
	int _moveTime{};
	std::vector<double> _restTimes;
};
