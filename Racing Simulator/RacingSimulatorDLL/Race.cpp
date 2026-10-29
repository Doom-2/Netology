//#include "Vehicle.h"
#include "Race.h"
#include "Vehicles.h"

#include <memory>
#include <stdexcept>

namespace {
	// Factory creates an object of disired class, and return a pointer of base class Vehicle
	std::unique_ptr<Vehicle> createVehicle(Race::VehicleModel vm) {
		switch (vm) {
		case Race::VehicleModel::CAMEL:
			return std::make_unique<Camel>();
		case Race::VehicleModel::FAST_CAMEL:
			return std::make_unique<FastCamel>();
		case Race::VehicleModel::CENTAUR:
			return std::make_unique<Centaur>();
		case Race::VehicleModel::SUPER_BOOTS:
			return std::make_unique<SuperBoots>();
		case Race::VehicleModel::MAGIC_CARPET:
			return std::make_unique<MagicCarpet>();
		case Race::VehicleModel::EAGLE:
			return std::make_unique<Eagle>();
		case Race::VehicleModel::BROOM:
			return std::make_unique<Broom>();
		default:
			throw std::invalid_argument("Invalid vehicle model");
		}
		return nullptr; // This line will never be reached, but is added to avoid compiler warnings
	}
}

Race::Race(int rt, int dist) : _rt(static_cast<RaceType>(rt)), _dist(dist) {}

void Race::registerVehicle(VehicleModel vm, std::string& vehicleName, double& vehicleTime) {
	if (_rt == RaceType::GROUND && vm > VehicleModel::SUPER_BOOTS ||
		_rt == RaceType::AIR && vm < VehicleModel::MAGIC_CARPET)
		throw std::logic_error("Попытка зарегистрировать неправильный тип транспортного средства!");

	const std::unique_ptr<Vehicle> vehicle = createVehicle(vm);
	vehicleName = vehicle->getName();
	vehicleTime = vehicle->calcRaceTime(_dist);

	if (!_registered.insert(vm).second)
		throw std::overflow_error(vehicle->getName() + " уже зарегистрирован!");
}

int Race::getVehicleCount() const {
	return static_cast<int>(_registered.size());
}

int Race::getRaceDist() const {
	return _dist;
}

Race::RaceType Race::getRaceType() const {
	return _rt;
}
