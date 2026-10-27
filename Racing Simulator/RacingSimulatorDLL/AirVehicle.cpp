#include "AirVehicle.h"

AirVehicle::AirVehicle(const std::string& name, int speed, int baseReduction)
	: Vehicle(name, speed), _baseReduction(baseReduction) {}

int AirVehicle::distReductionPercent(int /*dist*/) const {
	return _baseReduction; ;
}

double AirVehicle::calcRaceTime(int dist) const {
	return (dist * (1-distReductionPercent(dist) / 100.0)) / _speed;
}
