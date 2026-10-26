#include "Broom.h"

Broom::Broom() : AirVehicle("Метла", 20) {}


double Broom::calcRaceTime(int dist) {
	return dist * (1 - (dist / 1000) / 100.0) / _speed;
}
