#include "DebitCard.h"
#include <ctime>
#include <cstdlib>

DebitCard::DebitCard() {
    // Constructor implementation
}

void DebitCard::issueDebitCard(Account& account) {
    // Generate a random card number (16 digits)
    cardNumber = generateRandomCardNumber();

    // Generate a random CVV (3 digits)
    cvv = generateRandomCVV();

    // Generate a random expiration date (MM/YYYY)
    generateRandomExpirationDate();

    // Associate the card with the account
    account.setDebitCard(*this);
}

string DebitCard::generateRandomCardNumber() {
    string cardNumber;
    for (int i = 0; i < 16; ++i) {
        cardNumber += to_string(rand() % 10); // Append a random digit (0-9)
    }
    return cardNumber;
}

string DebitCard::generateRandomCVV() {
    return to_string(100 + rand() % 900); // Generate a random 3-digit number
}

void DebitCard::generateRandomExpirationDate() {
    // Generate a random month (1-12)
    int month = 1 + rand() % 12;
    // Generate a random year after 2026
    int year = 2026 + rand() % 10;
    expirationDate = to_string(month) + "/" + to_string(year);
}
#include "DebitCard.h"
#include <ctime>
#include <cstdlib>

DebitCard::DebitCard() {
    // Constructor implementation
}

void DebitCard::issueDebitCard(Account& account) {
    // Generate a random card number (16 digits)
    cardNumber = generateRandomCardNumber();

    // Generate a random CVV (3 digits)
    cvv = generateRandomCVV();

    // Generate a random expiration date (MM/YYYY)
    generateRandomExpirationDate();

    // Associate the card with the account
    account.setDebitCard(*this);
}

string DebitCard::generateRandomCardNumber() {
    string cardNumber;
    for (int i = 0; i < 16; ++i) {
        cardNumber += to_string(rand() % 10); // Append a random digit (0-9)
    }
    return cardNumber;
}

string DebitCard::generateRandomCVV() {
    return to_string(100 + rand() % 900); // Generate a random 3-digit number
}

void DebitCard::generateRandomExpirationDate() {
    // Generate a random month (1-12)
    int month = 1 + rand() % 12;
    // Generate a random year after 2026
    int year = 2026 + rand() % 10;
    expirationDate = to_string(month) + "/" + to_string(year);
}
