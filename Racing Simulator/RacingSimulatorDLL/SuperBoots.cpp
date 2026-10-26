#include "SuperBoots.h"

SuperBoots::SuperBoots() : GroundVehicle("Ботинки-вездеходы", 6, 60) {
	_breakTime = 10;
};

double SuperBoots::calcRaceTime(int dist) {
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
		return static_cast<double>(dist / _speed) + _breakTime + (_breakTime - 5) * (_breakNumber - 1);
		break;
	}
}
