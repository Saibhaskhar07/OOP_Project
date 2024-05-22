#include <string>
std::string Cards::getType() const { // Method to get card type
    return type; // Return card type
}

long long int Cards::getNumber() const { // Method to get card number
    return number; // Return card number
}

std::string Cards::getStart() const { // Method to get card start date
    return start; // Return start date
}

std::string Cards::getExpiry() const { // Method to get card expiry date
    return expiry; // Return expiry date
}

int Cards::getCVV() const { // Method to get card CVV
    return cvv; // Return CVV
}

double Cards::getLimit() const { // Method to get card limit
    return limit; // Return limit
}

bool Cards::getStatus() const { // Method to get card status
    return active; // Return status
}

void Cards::activateCard() { // Method to activate card
    active = true; // Set active to true
}

void Cards::deactivateCard() { // Method to deactivate card
    active = false; // Set active to false
}

void Cards::updateLimit(double newLimit) { // Method to update card limit
    limit = newLimit; // Update limit
}

void Cards::displayCardDetails() const { // Method to display card details
    std::cout << "Card Type: " << type << "\n" // Print card type
              << "Card Number: " << number << "\n" // Print card number
              << "Start Date: " << start << "\n" // Print start date
              << "Expiry Date: " << expiry << "\n" // Print expiry date
              << "CVV: " << cvv << "\n" // Print CVV
              << "Limit: " << limit << "\n" // Print limit
              << "Active: " << (active ? "Yes" : "No") << "\n\n"; // Print active status
} ;