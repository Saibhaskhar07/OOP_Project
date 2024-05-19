#include "Commercial.h"

namespace bankeasy {

Commercial::Commercial() : Accounts() {}

std::string Commercial::type() const {
    return "Commercial";
}

void Commercial::bookAppointment() const {
    std::string date, time;
    std::cout << "Enter appointment date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter appointment time (HH:MM): ";
    std::cin >> time;
    std::cout << "Appointment booked for " << date << " at " << time << ".\n\n";
}

} // namespace bankeasy
