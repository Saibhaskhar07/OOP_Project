#include "Cards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace bankeasy {

Cards::Cards(const std::string& cardType, long int cardNumber, const std::string& cardStart, const std::string& cardExpiry, int cvv, double limit)
    : cardType(cardType), cardNumber(cardNumber), cardStart(cardStart), cardExpiry(cardExpiry), cvv(cvv), limit(limit), isActive(false) {}

void Cards::activateCard() {
    isActive = true;
    std::cout << "Card activated successfully.\n\n";
}

void Cards::deactivateCard() {
    isActive = false;
    std::cout << "Card deactivated successfully.\n\n";
}

void Cards::updateLimit(double newLimit) {
    limit = newLimit;
    std::cout << "Card limit updated successfully.\n\n";
}

void Cards::displayCardDetails() const {
    std::cout << "Card Type: " << cardType << "\n";
    std::cout << "Card Number: " << cardNumber << "\n";
    std::cout << "Card Start Date: " << cardStart << "\n";
    std::cout << "Card Expiry Date: " << cardExpiry << "\n";
    std::cout << "CVV: " << cvv << "\n";
    std::cout << "Limit: $" << limit << "\n";
    std::cout << "Status: " << (isActive ? "Active" : "Inactive") << "\n\n";
}

// Accessor methods
std::string Cards::getType() const {
    return cardType;
}

long int Cards::getNumber() const {
    return cardNumber;
}

std::string Cards::getStart() const {
    return cardStart;
}

std::string Cards::getExpiry() const {
    return cardExpiry;
}

int Cards::getCVV() const {
    return cvv;
}

double Cards::getLimit() const {
    return limit;
}

bool Cards::getStatus() const {
    return isActive;
}

} // namespace bankeasy

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

long int generateRandomCardNumber() {
    long int cardNumber = 0;
    for (int i = 0; i < 16; ++i) {
        cardNumber = cardNumber * 10 + generateRandomNumber(0, 9);
    }
    return cardNumber;
}

int generateRandomCVV() {
    return generateRandomNumber(100, 999);
}

int main() {
    srand(time(0));

    std::string cardType = "Credit";
    long int cardNumber = generateRandomCardNumber();
    std::string cardStart = "05/24";
    std::string cardExpiry = "06/26";
    int cvv = generateRandomCVV();
    double limit = 5000.00;

    bankeasy::Cards card(cardType, cardNumber, cardStart, cardExpiry, cvv, limit);
    card.displayCardDetails();

    return 0;
}
