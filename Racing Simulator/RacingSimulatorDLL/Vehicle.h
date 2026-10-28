#pragma once

#include <string>

// Abstract base class for all vehicles
class Vehicle
{
protected:
	std::string _name;
	int _speed;

public:
	Vehicle(const std::string name, int speed);
	
	// Ensures derived destructors run when deleting through a base pointer.
	virtual ~Vehicle() = default;

	const std::string getName() const;

	// Pure virtual function implemented by derived classes to calculate the time for a distance.
	virtual double calcRaceTime(int dist) const = 0;
};
