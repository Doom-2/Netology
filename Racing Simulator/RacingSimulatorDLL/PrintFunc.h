#pragma once
#include "VehicleData.h"
#include "Race.h"

void printRaceStatistics(vehicleData* vData, int size);

void printRaceTypeList();

void printRaceTitle(Race& r);

void printModeMenu();

void printRetryOrFinish();

void printVehicleList();

void printvehicleDataList(Race& r, vehicleData* vDataArray);
