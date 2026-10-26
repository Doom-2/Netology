#include "FastCamel.h"

FastCamel::FastCamel() : GroundVehicle("Верблюд-быстроход", 40, 10) {
	_breakTime = 5;
};

double FastCamel::calcRaceTime(int dist) {
	calcBrakeNumber(dist);
	switch (_breakNumber)
	{
	case 0:
		return static_cast<double>(dist / _speed);
		break;
	case 1:
		return static_cast<double>(dist / _speed) + _breakTime;
		break;
	case 2:
		return static_cast<double>(dist / _speed) + 2 * _breakTime + 1.5;
		break;
	default: //number of breakes > 2
		return static_cast<double>(dist / _speed) + 2 * _breakTime + 1.5 + (_breakTime + 3) * (_breakNumber - 1);
		break;
	}
}
