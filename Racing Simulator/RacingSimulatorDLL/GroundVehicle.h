#pragma once

#include <vector>
#include "Vehicle.h"

class GroundVehicle : public Vehicle
{
protected:
	int _moveTime{};
	int _breakTime{};
	int _breakNumber{};
	std::vector<double> _restTimes;

public:

	GroundVehicle(const std::string& name, const int& speed, const int& moveTime);

	GroundVehicle(const std::string& name, int speed, int moveTime, std::vector<double> restTimes);


	void calcBrakeNumber(int dist);
};
