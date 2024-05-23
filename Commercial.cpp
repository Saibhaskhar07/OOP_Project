#include "Commercial.h"
#include <iostream>
#include "Utils.h"

namespace bankeasy { // Define namespace bankeasy

Commercial::Commercial() : Accounts() {} // Constructor initializes base Accounts class

std::string Commercial::type() const {
    return "Commercial"; // Return the account type as commercial
}

void Commercial::bookAppointment() const { // For making a prompt requesting to book appointment
    std::string date, time;
    std::cout << "Enter appointment date (YYYY-MM-DD): ";
    date = getValidatedDateInput();
    std::cout << "Enter appointment time (HH:MM): ";
    time = getValidatedTimeInput();
    std::cout << "Appointment booked for " << date << " at " << time << ".\n";
}

} // end of namespace bankeasy