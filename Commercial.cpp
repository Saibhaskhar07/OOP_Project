#include "Commercial.h" // Include header file for Commercial class
#include <iostream> // Include necessary header files
#include "Utils.h" // Include header file for utility functions

namespace bankeasy { // Begin namespace bankeasy

Commercial::Commercial() : Accounts() {} // Constructor for Commercial class

std::string Commercial::type() const { // Method to return account type
    return "Commercial"; // Return Commercial account type
}

void Commercial::bookAppointment() const { // Method to book appointment
    std::string date, time; // Declare variables for date and time
    std::cout << "Enter appointment date (YYYY-MM-DD): "; // Prompt for appointment date
    date = getValidatedDateInput(); // Get validated date input
    std::cout << "Enter appointment time (HH:MM): "; // Prompt for appointment time
    time = getValidatedTimeInput(); // Get validated time input
    std::cout << "Appointment booked for " << date << " at " << time << ".\n"; // Print booking confirmation
}

} // End namespace bankeasy
