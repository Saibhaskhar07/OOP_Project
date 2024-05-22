#ifndef USER_H
#define USER_H

#include "StudentLoan.h"
#include "PersonalLoan.h"
#include "ScheduledPayment.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <random>
#include <sstream>
#include "Cards.h"

namespace bankeasy {

// Function to generate a random 16-digit card number
std::string generateRandomCardNumber();

// Function to generate a random 3-digit CVV number
int generateRandomCVV();

// Function to generate a random account number
std::string generateAccountNumber();

class User {
public:
    // Constructor with parameters including a loan pointer
    User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, Loan* loan);
    // Destructor
    ~User();

    std::string getName() const; // Getter for name
    std::string getEmail() const; // Getter for email
    std::string getPin() const; // Getter for pin
    double getBalance() const; // Getter for balance
    std::string getAccountType() const; // Getter for account type
    std::string getAccountNumber() const; // Getter for account number

    void deposit(double amount); // Function to deposit money
    void withdraw(double amount); // Function to withdraw money

    void save(std::ofstream& out) const; // Function to save user data to file
    static User load(std::ifstream& in); // Static function to load user data from file

    void changeInterestRate(double newRate); // Function to change loan interest rate
    void freezeTransactions(); // Function to freeze transactions
    void unfreezeTransactions(); // Function to unfreeze transactions
    void updateLoginDetails(const std::string& newEmail, const std::string& newPin); // Function to update login details
    void processScheduledPayments(); // Function to process scheduled payments
    void updateDetails(const std::string& detailType, const std::string& newValue); // Function to update user details
    void statements() const; // Function to display transaction statements
    void schedulePayment(const std::string& purpose, double amount, const std::string& frequency); // Function to schedule payment
    void addCard(const Cards& card); // Function to add a card
    void manageCards(); // Function to manage user's cards

private:
    std::string name; // Member variable for name
    std::string email; // Member variable for email
    std::string pin; // Member variable for pin
    double balance; // Member variable for balance
    std::string accountType; // Member variable for account type
    Loan* loan; // Member variable for loan
    bool transactionsFrozen; // Member variable to track transaction freeze
    std::string accountNumber; // Member variable for account number
    std::vector<ScheduledPayment> scheduledPayments; // Member variable for scheduled payments
    std::vector<Cards> cards; // Member variable for cards
};

} // namespace bankeasy

#endif // USER_H
