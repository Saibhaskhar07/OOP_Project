#include "Commercial.h"
#include "Utils.h"
#include <iostream>

namespace bankeasy {

Commercial::Commercial() {}

std::string Commercial::type() const {
    return "Commercial";
}

void Commercial::bookAppointment() {
    std::string date, time;
    std::cout << "Enter the date for appointment (YYYY-MM-DD): ";
    date = getValidatedStringInput();
    std::cout << "Enter the time for appointment (HH:MM): ";
    time = getValidatedStringInput();
    std::cout << "Appointment booked successfully on " << date << " at " << time << ".\n\n";
}

} // namespace bankeasy
