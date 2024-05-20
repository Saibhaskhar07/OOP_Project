#include "Utils.h"
#include <iostream>
#include <limits>
#include <regex>

// Function definitions
void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidatedIntInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

double getValidatedDoubleInput() {
    double input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

std::string getValidatedStringInput() {
    std::string input;
    std::getline(std::cin, input);
    while (input.empty() || std::any_of(input.begin(), input.end(), ::isdigit)) {
        std::cout << "Invalid input. Please enter a valid text: ";
        std::getline(std::cin, input);
    }
    return input;
}

std::string getValidatedEmailInput() {
    std::string email;
    std::regex emailRegex("^[\\w-]+@[\\w-]+\\.[\\w-]+$");
    std::getline(std::cin, email);
    while (!std::regex_match(email, emailRegex)) {
        std::cout << "Invalid email. Please enter a valid email address: ";
        std::getline(std::cin, email);
    }
    return email;
}

std::string getValidatedPinInput() {
    std::string pin;
    std::getline(std::cin, pin);
    while (pin.length() != 4 || !std::all_of(pin.begin(), pin.end(), ::isdigit)) {
        std::cout << "Invalid PIN. Please enter a 4-digit number: ";
        std::getline(std::cin, pin);
    }
    return pin;
}
