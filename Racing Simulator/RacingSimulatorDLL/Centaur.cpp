#include "Centaur.h"

Centaur::Centaur() : GroundVehicle("Кентавр", 15, 8) {
	_breakTime = 2;
};

double Centaur::calcRaceTime(int dist) {
	calcBrakeNumber(dist);
	switch (_breakNumber)
	{
	case 0:
		return static_cast<double>(dist / _speed);
		break;
	case 1:
		return static_cast<double>(dist / _speed) + _breakTime;
		break;
	default: //number of breakes > 2
		return static_cast<double>(dist / _speed) + _breakTime + _breakTime * (_breakNumber - 1);
		break;
	}
}
