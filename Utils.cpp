#include "Utils.h"
#include <iostream>
#include <limits>
#include <regex>
#include <ctime>

// Function to clear input stream
void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get validated integer input
int getValidatedIntInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

// Function to get validated long long integer input
long long getValidatedLongLongIntInput() {
    long long input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

// Function to get validated double input
double getValidatedDoubleInput() {
    double input;
    while (!(std::cin >> input)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        clearInputStream();
    }
    clearInputStream();
    return input;
}

// Function to get validated string input
std::string getValidatedStringInput() {
    std::string input;
    std::getline(std::cin, input);
    while (input.empty() || std::any_of(input.begin(), input.end(), ::isdigit)) {
        std::cout << "Invalid input. Please enter valid text: ";
        std::getline(std::cin, input);
    }
    return input;
}

// Function to get validated email input
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

// Function to get validated PIN input
std::string getValidatedPinInput() {
    std::string pin;
    std::getline(std::cin, pin);
    while (pin.length() != 4 || !std::all_of(pin.begin(), pin.end(), ::isdigit)) {
        std::cout << "Invalid PIN. Please enter a 4-digit number: ";
        std::getline(std::cin, pin);
    }
    return pin;
}

// Function to get validated date input
std::string getValidatedDateInput() {
    std::string date;
    std::regex dateRegex("^\\d{4}-\\d{2}-\\d{2}$"); // YYYY-MM-DD format
    std::getline(std::cin, date);
    std::tm tm = {};
    while (!std::regex_match(date, dateRegex) || !strptime(date.c_str(), "%Y-%m-%d", &tm) || std::difftime(std::mktime(&tm), std::time(nullptr)) < 0) {
        std::cout << "Invalid date. Please enter a valid date (YYYY-MM-DD) and not a past date: ";
        std::getline(std::cin, date);
    }
    return date;
}

// Function to get validated time input
std::string getValidatedTimeInput() {
    std::string time;
    std::regex timeRegex("^\\d{2}:\\d{2}$"); // HH:MM format
    std::getline(std::cin, time);
    std::tm tm = {};
    while (!std::regex_match(time, timeRegex) || !strptime(time.c_str(), "%H:%M", &tm)) {
        std::cout << "Invalid time. Please enter a valid time (HH:MM): ";
        std::getline(std::cin, time);
    }
    return time;
}