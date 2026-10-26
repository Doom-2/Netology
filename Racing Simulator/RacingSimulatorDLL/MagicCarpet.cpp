#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : AirVehicle("Ковер-самолёт", 10) {}


double MagicCarpet::calcRaceTime(int dist) {
	if (dist < 1000)
		return dist / _speed;
	else if (dist < 5000)
		return dist * (1 - (_distReductionFactor + 3)/ 100.0) / _speed;
	else if (dist < 10000)
		return dist * (1 - (_distReductionFactor + 10) / 100.0) / _speed;
	else
		return dist * (1 - (_distReductionFactor + 5) / 100.0) / _speed;
}
