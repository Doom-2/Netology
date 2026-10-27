#include "AirVehicle.h"

AirVehicle::AirVehicle(const std::string& name, const int& speed)
	: Vehicle(name, speed) {}

int AirVehicle::distReductionPercent(int /*dist*/) const {
	return _distReductionFactor	;
}

double AirVehicle::calcRaceTime(int dist) const {
	return (dist * (1-distReductionPercent(dist) / 100.0)) / _speed;
}
