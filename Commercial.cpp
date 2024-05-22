#include "Commercial.h"
#include <iostream>
#include "Utils.h"

namespace bankeasy {

Commercial::Commercial() : Accounts() {}

std::string Commercial::type() const {
    return "Commercial";
}

void Commercial::bookAppointment() const {
    std::string date, time;
    std::cout << "Enter appointment date (YYYY-MM-DD): ";
    date = getValidatedDateInput();
    std::cout << "Enter appointment time (HH:MM): ";
    time = getValidatedTimeInput();
    std::cout << "Appointment booked for " << date << " at " << time << ".\n";
}

} // namespace bankeasy