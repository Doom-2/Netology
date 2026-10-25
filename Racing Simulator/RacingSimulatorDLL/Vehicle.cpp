#include "Vehicle.h"
#include <utility>


Vehicle::Vehicle(std::string name, int speed)
	: _name(std::move(name)), _speed(speed) {}

double Vehicle::calcRaceTime(int dist) const {
	return static_cast<double>(dist / _speed);
}

std::string Vehicle::getName() {
	return _name;
}
