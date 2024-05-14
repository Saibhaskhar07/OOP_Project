#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "Savings.h"

class DebitCard : public Savings {
private:
    string cardNumber;
    string expirationDate;
    string cvv;

public:
    DebitCard();
    void issueDebitCard(Account& account); // Method to issue a debit card to a person
    string getCardNumber() { return cardNumber; } // Getter method for card number
    string getExpirationDate() { return expirationDate; } // Getter method for expiration date
    string getCVV() { return cvv; } // Getter method for CVV
private:
    string generateRandomCardNumber();
    string generateRandomCVV();
    void generateRandomExpirationDate();
};

#endif
