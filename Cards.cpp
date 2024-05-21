#include "Cards.h"
#include <iostream>

namespace bankeasy {

Cards::Cards(const std::string& type, long long int number, const std::string& start, const std::string& expiry, int cvv, double limit)
    : type(type), number(number), start(start), expiry(expiry), cvv(cvv), limit(limit), active(false) {}

std::string Cards::getType() const {
    return type;
}

long long int Cards::getNumber() const {
    return number;
}

std::string Cards::getStart() const {
    return start;
}

std::string Cards::getExpiry() const {
    return expiry;
}

int Cards::getCVV() const {
    return cvv;
}

double Cards::getLimit() const {
    return limit;
}

bool Cards::getStatus() const {
    return active;
}

void Cards::activateCard() {
    active = true;
}

void Cards::deactivateCard() {
    active = false;
}

void Cards::updateLimit(double newLimit) {
    limit = newLimit;
}

void Cards::displayCardDetails() const {
    std::cout << "Card Type: " << type << "\n"
              << "Card Number: " << number << "\n"
              << "Start Date: " << start << "\n"
              << "Expiry Date: " << expiry << "\n"
              << "CVV: " << cvv << "\n"
              << "Limit: " << limit << "\n"
              << "Active: " << (active ? "Yes" : "No") << "\n\n";
}

} // namespace bankeasy
