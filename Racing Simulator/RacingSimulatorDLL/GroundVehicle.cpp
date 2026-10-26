#include "GroundVehicle.h"
#include <utility>

GroundVehicle::GroundVehicle(const std::string& name, const int& speed, const int& moveTime)
	: Vehicle(name, speed), _moveTime(moveTime) {
}

GroundVehicle::GroundVehicle(const std::string& name, int speed, int moveTime, std::vector<double> restTimes)
	: Vehicle(name, speed), _moveTime(moveTime), _restTimes(std::move(restTimes))
{
	if (_restTimes.empty())
		_restTimes.push_back(0.0);
}

void GroundVehicle::calcBrakeNumber(int dist) {
	if ((dist / _speed) < _moveTime)
		_breakNumber = 0;
	else
		if ((dist / _speed) % _moveTime == 0)
			_breakNumber = (dist / _speed) / _moveTime - 1;
		else
			_breakNumber = (dist / _speed) / _moveTime;
}
