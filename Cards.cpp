#include "Cards.h"
#include <iostream>

namespace bankeasy { // Define namespace bankeasy

Cards::Cards(const std::string& type, long long int number, const std::string& start, const std::string& expiry, int cvv, double limit)
    : type(type), number(number), start(start), expiry(expiry), cvv(cvv), limit(limit), active(false) {} // Constructor

std::string Cards::getType() const {
    return type; // Get card type
}

long long int Cards::getNumber() const {
    return number; // Get card number
}

std::string Cards::getStart() const {
    return start; // Get card start date
}

std::string Cards::getExpiry() const {
    return expiry; // Get card epiry date
}

int Cards::getCVV() const {
    return cvv; // Get Card CVV
}

double Cards::getLimit() const {
    return limit; // Get card limit
}

bool Cards::getStatus() const {
    return active; //  Get card status (active/inactive)
}

void Cards::activateCard() {
    active = true; // Activate the card
}

void Cards::deactivateCard() {
    active = false; // Deactivate the card
}

void Cards::updateLimit(double newLimit) {
    limit = newLimit; // Update the Card limit
}

void Cards::displayCardDetails() const { // Show Card parameters together
    std::cout << "Card Type: " << type << "\n"
              << "Card Number: " << number << "\n"
              << "Start Date: " << start << "\n"
              << "Expiry Date: " << expiry << "\n"
              << "CVV: " << cvv << "\n"
              << "Limit: " << limit << "\n"
              << "Active: " << (active ? "Yes" : "No") << "\n\n";
}

} // namespace bankeasy