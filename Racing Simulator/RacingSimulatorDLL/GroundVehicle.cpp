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

// Returns the number of rest stops required for the given distance.
int GroundVehicle::calcRestCount(int dist) const {
	const long long legDist = static_cast<long long>(_speed) * _moveTime;
	if (dist <= legDist)
		return 0;
	return static_cast<int>((dist - 1) / legDist);
}

// Claculates the total race time , includining required rest periods
double GroundVehicle::calcRaceTime(int dist) const {
	// Calculate travel time without rests
	double time = static_cast<double>(dist) / _speed;

	const int restCount = calcRestCount(dist);
	const int scheduled = static_cast<int>(_restTimes.size());

	// Add the scheduled rest durations
	for (int i = 0; i < std::min(restCount, scheduled); ++i) {
		time += _restTimes[i];
	}

	// If there are more rests than scheduled, add the last rest duration for the remaining rests
	if (restCount > scheduled) {
		time += _restTimes.back() * (restCount - scheduled);
	}

	return time;
}
