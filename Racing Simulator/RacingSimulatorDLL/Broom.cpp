#include "Broom.h"

Broom::Broom() : AirVehicle("Метла", 20) {}

// Reduce the distance by 1% for every full 1,000 units.
int Broom::distReductionPercent(int dist) const {
	return dist / 1000;
}
