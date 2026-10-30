#pragma once

#include <cstddef>
#include <set>
#include <string>

// Race: stores type and distance, enforces registration rules, tracks registered vehicles.
class Race
{
public:
	enum class RaceType
	{
		GROUND = 1,
		AIR,
		MIXED
	};

	enum class VehicleModel
	{
		CAMEL = 1,
		FAST_CAMEL,
		CENTAUR,
		SUPER_BOOTS,
		MAGIC_CARPET,
		EAGLE,
		BROOM
	};

	Race(int rt, int dist);

	// Registers a vehicle; outputs name and race time via reference params.
	// Throws: domain_error (invalid number), logic_error (wrong race type),
	//         overflow_error (vehicle already registered).
	void registerVehicle(VehicleModel vm, std::string& vehicleName, double& vehicleTime);

	int getVehicleCount() const;

	int getRaceDist() const;

	RaceType getRaceType() const;

protected:
	RaceType _rt{RaceType::GROUND};
	int _dist{};
	std::set<VehicleModel> _registered; // replaces static counters in each class
};
