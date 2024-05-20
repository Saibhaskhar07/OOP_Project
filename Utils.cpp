#include "Utils.h"
#include <iostream>
#include <limits>

// Function definitions
void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidatedIntInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

double getValidatedDoubleInput() {
    double input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

std::string getValidatedStringInput() {
    std::string input;
    std::getline(std::cin, input);
    while (input.empty()) {
        std::cout << "Input cannot be empty. Please enter a value: ";
        std::getline(std::cin, input);
    }
    return input;
}