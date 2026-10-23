// Auxiliary Functions

#include "AuxFunc.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// Sorts an array of vehicleData struct instances by vehicleTime in ascending order
void bubbleSort(vehicleData* vData, int size) {
	bool swapped;

	// access each array element
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		//compare two adjacent array elements and swap them if necessary
		for (int j = 0; j < size - i - 1; j++) {
			if (vData[j].vehicleTime > vData[j + 1].vehicleTime) {
				vehicleData temp = vData[j];
				vData[j] = vData[j + 1];
				vData[j + 1] = temp;
				swapped = true;
			}
		}

		// If no two elements were swapped, then break
		if (!swapped)
			break;
	}
}


// Checks for positive or non-negative integers, throws an error otherwise.
// Returns correct integer.
// Takes arguments indicating max allowed value and whether zero is allowed
namespace {

    enum class InputError {
        InvalidInteger,
        OutOfRange
    };

    // Prints an error message based on the configured range and error type.
    void printInputError(int maxNum, bool allowZero, InputError error) {
        if (maxNum > 0) {
            const int minValue = allowZero ? 0 : 1;
            const std::string range =
                (minValue == maxNum)
                ? std::to_string(maxNum)
                : std::to_string(minValue) + "-" + std::to_string(maxNum);

            std::cerr << "Ошибка ввода! Введите " << range << ".";
        }
        else if (error == InputError::OutOfRange) {
            std::cerr << "Некорректный ввод. Целое число должно быть "
                << (allowZero ? "неотрицательным." : "положительным.");
        }
        else {
            std::cerr << "Некорректный ввод. Допускается только целое число.";
        }

        std::cerr << "\n>";
    }

} // namespace

// Reads an integer from standard input, prompting again until it is valid.
// maxNum sets the upper limit (0 means no upper limit); allowZero sets the lower limit.
// Throws if maxNum is negative or input cannot be read.
int cinInt(int maxNum, bool allowZero) {
    // A negative maximum cannot describe a valid range.
    if (maxNum < 0) {
        throw std::invalid_argument("maxNum не может быть отрицательным");
    }

    const int minValue = allowZero ? 0 : 1;
    std::string line;

    while (true) {
        // Read one whole line so leftover characters cannot affect the next attempt.
        if (!std::getline(std::cin, line)) {
            if (std::cin.eof()) {
                throw std::runtime_error("Ввод закрыт");
            }
            throw std::runtime_error("Ошибка чтения ввода");
        }

        std::istringstream input(line);
        int value = 0;

        // If the line does not start with an integer, ask for another line.
        if (!(input >> value)) {
            printInputError(maxNum, allowZero, InputError::InvalidInteger);
            continue;
        }

        // Allow whitespace after the number, but reject any other trailing characters.
        input >> std::ws;
        if (!input.eof()) {
            printInputError(maxNum, allowZero, InputError::InvalidInteger);
            continue;
        }

        // Check the integer against the minimum and optional maximum.
        if (value < minValue || (maxNum > 0 && value > maxNum)) {
            printInputError(maxNum, allowZero, InputError::OutOfRange);
            continue;
        }

        return value;
    }
}

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::cout << "\033[2J\033[H" << std::flush;
#endif
}