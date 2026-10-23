#include "RacingSimulatorDLL/AuxFunc.h"
#include "RacingSimulatorDLL/PrintFunc.h"
#include "RacingSimulatorDLL/Vehicles.h"


int main()
{
	setlocale(LC_ALL, "russian");
	int raceType, dist, vehicleModel{}, mode{};
	double vehicleTime;

	while (true)
	{
		vehicleData* vehicleDataArray = new vehicleData[7];
		std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
		printRaceTypeList();
		raceType = cinInt(3);
		clearScreen();
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		dist = cinInt();
		Race race(raceType, dist);
		clearScreen();
		printRaceTitle(race);
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;

		// main logic
		while (true)
		{
			clearScreen();
			printRaceTitle(race);
			if (race.getVehicleCount())
				printvehicleDataList(race, vehicleDataArray);
			printVehicleList();
			while (true) {
				vehicleModel = cinInt(7, true);

				// if zero is entered and there are no registered vehicles
				if (vehicleModel == 0 && !race.getVehicleCount()) {
					clearScreen();
					printRaceTitle(race);
					std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
					printVehicleList();
					continue;
				}
				// if zero is entered and the number of registered vehicles is not enough to start the race
				else if (vehicleModel == 0 && race.getVehicleCount() < 2) {
					clearScreen();
					printRaceTitle(race);
					std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
					printvehicleDataList(race, vehicleDataArray);
					printVehicleList();
					continue;
				}
				// if zero is entered and the number of registered vehicles is enough to start the race
				else if (vehicleModel == 0 && race.getVehicleCount() >= 2)
					break;

				// if non-zero is entered, try to register the vehicle
				if (vehicleModel) {
					std::string vehicleName{};
					try {
						race.registerVehicle(vehicleModel, vehicleName, vehicleTime);
						clearScreen();
						std::cout << vehicleName << " успешно зарегистрирован!" << std::endl;
						vehicleDataArray[race.getVehicleCount() - 1].vehicleName = vehicleName;
						vehicleDataArray[race.getVehicleCount() - 1].vehicleTime = vehicleTime;
					}
					catch (std::exception& e) {
						clearScreen();
						std::cout << e.what() << std::endl;
					}
					printRaceTitle(race);
					if (race.getVehicleCount())
						printvehicleDataList(race, vehicleDataArray);
					printVehicleList();
					continue;
				}

			}
			clearScreen();
			printRaceTitle(race);
			printModeMenu();
			mode = cinInt(2);
			if (mode == 1)
				continue;
			if (mode == 2)
				break;
		}
		clearScreen();
		printRaceStatistics(vehicleDataArray, race.getVehicleCount());
		std::cout << std::endl;
		printRetryOrFinish();
		mode = cinInt(2);
		if (mode == 1) {
			delete[] vehicleDataArray;
			clearScreen();
			continue;
		}
		if (mode == 2) {
			delete[] vehicleDataArray;
			break;
		}
	}
}
