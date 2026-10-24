#pragma once
#include "VehicleData.h"
#include "Race.h"

void printRaceStatistics(vehicleData* vData, int size);

void printRaceTypeList();

void printRaceTitle(const Race& r);

void printModeMenu();

void printRetryOrFinish();

void printVehicleList();

void printvehicleDataList(const Race& r, vehicleData* vDataArray);
