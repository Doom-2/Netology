#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : AirVehicle("Ковер-самолёт", 10) {}

int MagicCarpet::distReductionPercent(int dist) const
{
	if (dist < 1000)
		return 0;
	else if (dist < 5000)
		return 3;
	else if (dist < 10000)
		return 10;
	else
		return 5;
}
