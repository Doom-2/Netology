#include "RacingSimulatorDLL/AuxFunc.h"
#include "RacingSimulatorDLL/PrintFunc.h"
#include "RacingSimulatorDLL/Vehicles.h"

#include <vector>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif


int main()
{
#ifdef _WIN32
	// The source files use UTF-8, so configure the console to use UTF-8 as well.
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif

	try
	{
		int raceType, dist, vehicleIndex{}, mode{};
		double vehicleTime;

		while (true)
		{
			// vector manages its own memory, replacing manual new[]/delete[].
			std::vector<vehicleData> vehicleDataArray(7);
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
					printvehicleDataList(race, vehicleDataArray.data());
				printVehicleList();
				while (true) {
					vehicleIndex = cinInt(7, true);

					// if zero is entered and there are no registered vehicles
					if (vehicleIndex == 0 && !race.getVehicleCount()) {
						clearScreen();
						printRaceTitle(race);
						std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
						printVehicleList();
						continue;
					}
					// if zero is entered and the number of registered vehicles is not enough to start the race
					else if (vehicleIndex == 0 && race.getVehicleCount() < 2) {
						clearScreen();
						printRaceTitle(race);
						std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
						printvehicleDataList(race, vehicleDataArray.data());
						printVehicleList();
						continue;
					}
					// if zero is entered and the number of registered vehicles is enough to start the race
					else if (vehicleIndex == 0 && race.getVehicleCount() >= 2)
						break;

					// if non-zero is entered, try to register the vehicle
					if (vehicleIndex) {
						auto vehicleModel = static_cast<Race::VehicleModel>(vehicleIndex);
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
							printvehicleDataList(race, vehicleDataArray.data());
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
			printRaceStatistics(vehicleDataArray.data(), race.getVehicleCount());
			std::cout << std::endl;
			printRetryOrFinish();
			mode = cinInt(2);
			if (mode == 1) {
				clearScreen();
				continue;
			}
			if (mode == 2)
				break;
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << std::endl << e.what() << std::endl;
		return 1;
	}
}
