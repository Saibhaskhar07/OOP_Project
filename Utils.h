#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <string>
#include <regex>
#include <ctime>
#include <sstream> // Added for std::istringstream

namespace bankeasy {

inline void clearInputStream() {// Function to clear input stream
    std::cin.clear();Clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore remaining characters in the input buffer
}

// Function to get validated string input from user
inline std::string getValidatedStringInput() {
    std::string input;
    while (true) {// Repeat until valid non-empty input is received
        std::getline(std::cin, input);
        if (!input.empty()) {// Check if input is not empty
            break;
        }
        std::cout << "Invalid input. Please enter a valid string: ";
    }
    return input;
}

inline std::string getValidatedEmailInput() { // Function to get validated email input from user
    std::string email;
    std::regex emailRegex(R"(^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$)");
    // Regular expression pattern for email validation
    while (true) {// Repeat until valid email input is received
        std::getline(std::cin, email);
        if (std::regex_match(email, emailRegex)) {
            break;
        }
        std::cout << "Invalid email format. Please enter a valid email: ";
    }
    return email;
}

inline std::string getValidatedPinInput() {// Function to get validated PIN input from user
    std::string pin;
    std::regex pinRegex(R"(\d{4})");
    while (true) { // Repeat until valid PIN input is received
        std::getline(std::cin, pin);
        if (std::regex_match(pin, pinRegex)) {
            break;
        }
        std::cout << "Invalid PIN format. Please enter a valid 4-digit PIN: ";
    }
    return pin;
}

// Function to get validated integer input from user
inline int getValidatedIntInput() {
    int input;
    while (true) {
        std::cin >> input;
        if (!std::cin.fail()) {
            clearInputStream();
            break;
        }
        clearInputStream();
        std::cout << "Invalid input. Please enter a valid number: ";
    }
    return input;
}

// Function to get validated double input from user
inline double getValidatedDoubleInput() {
    double input;
    while (true) {
        std::cin >> input;
        if (!std::cin.fail()) {
            clearInputStream();
            break;
        }
        clearInputStream();
        std::cout << "Invalid input. Please enter a valid number: ";
    }
    return input;
}

inline std::string getValidatedDateInput() {// Function to get validated date input from user
    std::string date;
    std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
    while (true) {
        std::getline(std::cin, date);
        if (std::regex_match(date, dateRegex)) {
            int year, month, day;
            char delimiter1, delimiter2;
            std::istringstream dateStream(date);
            dateStream >> year >> delimiter1 >> month >> delimiter2 >> day;
            if (delimiter1 == '-' && delimiter2 == '-' && dateStream && 
                month >= 1 && month <= 12 && day >= 1 && day <= 31) {
                std::tm tm = {};
                tm.tm_year = year - 1900;
                tm.tm_mon = month - 1;
                tm.tm_mday = day;
                std::time_t enteredTime = std::mktime(&tm);
                std::time_t currentTime = std::time(nullptr);
                if (enteredTime >= currentTime) {
                    break;
                } else {
                    std::cout << "The date cannot be in the past. Please enter a valid date: ";
                }
            } else {
                std::cout << "Invalid date format. Please enter a valid date (YYYY-MM-DD): ";
            }
        } else {
            std::cout << "Invalid date format. Please enter a valid date (YYYY-MM-DD): ";
        }
    }
    return date;
}

inline std::string getValidatedTimeInput() { // Function to get validated time input from user
    std::string time;
    std::regex timeRegex(R"(\d{2}:\d{2})");
    while (true) { // Repeat until valid time input is received
        std::getline(std::cin, time);
        if (std::regex_match(time, timeRegex)) {
            break;
        }
        std::cout << "Invalid time format. Please enter a valid time (HH:MM): ";
    }
    return time;
}

inline long long getValidatedLongLongIntInput() {// Function to get validated long long integer input from user
    long long input;
    while (true) {// Repeat until valid long long integer input is received
        std::cin >> input;
        if (!std::cin.fail()) {
            clearInputStream();
            break;
        }
        clearInputStream();
        std::cout << "Invalid input. Please enter a valid number: "; // Clear input stream to remove invalid characters
    }
    return input;
}

} // namespace bankeasy

#endif // UTILS_H
