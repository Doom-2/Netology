#pragma once

#include <iostream>
#include "Race.h"

class Vehicle
{
protected:
	std::string _name;
	int _speed;

public:
	Vehicle(const std::string name, int speed);
	
	virtual ~Vehicle() = default;

	const std::string getName() const;

	virtual double calcRaceTime(int dist) const = 0;
};
