#include "User.h"
#include "StudentLoan.h"
#include "PersonalLoan.h"
#include "ScheduledPayment.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <random>
#include <sstream>

namespace bankeasy {

// Function to generate a random 16-digit card number
std::string generateRandomCardNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    std::string cardNumber;
    for (int i = 0; i < 16; ++i) {
        cardNumber += std::to_string(dis(gen));
    }
    return cardNumber;
}

// Function to generate a random 3-digit CVV number
int generateRandomCVV() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 999);// Define uniform distribution for 3-digit numbers
    return dis(gen);
}

// Function to generate a random account number
std::string generateAccountNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> dis(1000000000LL, 9999999999LL);// Define uniform distribution for 10-digit numbers

    std::ostringstream oss;
    oss << dis(gen);
    return oss.str();
}

// Constructor for User class
User::User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, Loan* loan)
    : name(name), email(email), pin(pin), balance(loan ? loan->getAmount() : 0), accountType(accountType), loan(loan), transactionsFrozen(false), accountNumber(generateAccountNumber()) {}

// Destructor for User class
User::~User() {
    delete loan;
}

// Getter for user's name
std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {// Getter for user's email
    return email;
}

std::string User::getPin() const {// Getter for user's PIN
    return pin;
}

double User::getBalance() const {// Getter for user's balance
    return balance;
}

std::string User::getAccountType() const {// Getter for user's account type
    return accountType;
}

std::string User::getAccountNumber() const {// Getter for user's account number
    return accountNumber;
}

// Function to deposit money into user's account
void User::deposit(double amount) {
    if (transactionsFrozen) {
        std::cout << "Transactions are frozen for this account.\n\n";// Print message if transactions are frozen
        return;
    }
    if (amount > 0) { // Check if amount is valid
        balance += amount;
        std::cout << "Deposited successfully.\n\n";
    }
}

void User::withdraw(double amount) {// Function to withdraw money from user's account
    if (transactionsFrozen) { // Check if transactions are frozen
        std::cout << "Transactions are frozen for this account.\n\n";
        return;
    }
    if (amount > 0 && amount <= balance) {// Check if withdrawal amount is valid
        balance -= amount;
        std::cout << "Withdrawn successfully.\n\n";
    } else {
        std::cout << "Withdrawal failed. Insufficient balance.\n\n";
    }
}

void User::save(std::ofstream& out) const {// Function to save user details to file
    out << name << '\n' << email << '\n' << pin << '\n' << balance << '\n' << accountType << '\n' << accountNumber << '\n';
    if (loan) {// Write loan details if loan exists
        out << loan->getLoanType() << '\n' << loan->getAmount() << '\n' << loan->getTenure() << '\n';
        if (loan->getLoanType() == "Student Loan") {// Write additional details for specific loan types
            StudentLoan* studentLoan = dynamic_cast<StudentLoan*>(loan);
            out << studentLoan->getCourse() << '\n' << studentLoan->getPlaceOfStudy() << '\n';
        } else if (loan->getLoanType() == "Personal Loan") {
            PersonalLoan* personalLoan = dynamic_cast<PersonalLoan*>(loan);
            out << personalLoan->getPurpose() << '\n';
        }
    } else {
        out << "No Loan\n";
    }
    
    // Write transaction freeze status
    out << transactionsFrozen << '\n';
    out << scheduledPayments.size() << '\n';
    for (const auto& payment : scheduledPayments) {
        out << payment.purpose << '\n' << payment.amount << '\n' << payment.frequency << '\n';
    }
    
    // Write card details
    out << cards.size() << '\n';
    for (const auto& card : cards) {
        out << card.getType() << '\n' << card.getNumber() << '\n' << card.getStart() << '\n' << card.getExpiry() << '\n' << card.getCVV() << '\n' << card.getLimit() << '\n' << card.getStatus() << '\n';
    }
}

User User::load(std::ifstream& in) {// Function to load user details from file
    std::string name, email, pin, accountType, loanType, accountNumber;// Read user details from file
    double balance, amount;
    int tenure, numPayments, numCards;
    bool transactionsFrozen;
    std::getline(in, name);
    std::getline(in, email);
    std::getline(in, pin);
    in >> balance;
    in.ignore();
    std::getline(in, accountType);
    std::getline(in, accountNumber);
    std::getline(in, loanType);
    Loan* loan = nullptr;
    if (loanType != "No Loan") { // Read loan details if available
        in >> amount >> tenure;
        in.ignore();
        if (loanType == "Student Loan") {
            std::string course, placeOfStudy;
            std::getline(in, course);
            std::getline(in, placeOfStudy);
            loan = new StudentLoan(amount, tenure, course, placeOfStudy);
        } else if (loanType == "Personal Loan") {
            std::string purpose;
            std::getline(in, purpose);
            loan = new PersonalLoan(amount, tenure, purpose);
        }
    }
    User user(name, email, pin, accountType, loan);// Create user object with loaded details
    user.balance = balance;
    user.accountNumber = accountNumber;
    in >> transactionsFrozen;
    user.transactionsFrozen = transactionsFrozen;
    in.ignore();
    // Read scheduled payments
    in >> numPayments;
    in.ignore();
    for (int i = 0; i < numPayments; ++i) {
        ScheduledPayment payment;
        std::getline(in, payment.purpose);
        in >> payment.amount;
        in.ignore();
        std::getline(in, payment.frequency);
        user.scheduledPayments.push_back(payment);
    }
     // Read card details
    in >> numCards;
    in.ignore();
    for (int i = 0; i < numCards; ++i) {
        std::string cardType, cardStart, cardExpiry;
        long long int cardNumber;
        int cvv;
        double limit;
        bool isActive;
        std::getline(in, cardType);
        in >> cardNumber;
        in.ignore();
        std::getline(in, cardStart);
        std::getline(in, cardExpiry);
        in >> cvv;
        in.ignore();
        in >> limit;
        in.ignore();
        in >> isActive;
        in.ignore();
        Cards card(cardType, cardNumber, cardStart, cardExpiry, cvv, limit);
        if (isActive) {
            card.activateCard();
        } else {
            card.deactivateCard();
        }
        user.cards.push_back(card);
    }
    return user; // Return loaded user object
}

void User::changeInterestRate(double newRate) {// Function to change interest rate of user's loan
    if (loan) {// Change interest rate if loan exists
        loan->changeInterestRate(newRate);
    }
}

void User::freezeTransactions() {// Function to freeze transactions for user's account
    transactionsFrozen = true;// Set transactionsFrozen flag to true
}

void User::unfreezeTransactions() {// Function to unfreeze transactions for user's account
    transactionsFrozen = false; // Set transactionsFrozen flag to false
}
// Function to update user's login details
void User::updateLoginDetails(const std::string& newEmail, const std::string& newPin) {
    email = newEmail; // Update email
    pin = newPin; // Update PIN
}

void User::processScheduledPayments() {// Function to process scheduled payments for user
    if (scheduledPayments.empty()) {
        return;// If no scheduled payments, return
    }
    std::time_t now = std::time(nullptr);// Get current time
    for (const auto& payment : scheduledPayments) {// Process each scheduled payment
        if (payment.frequency == "monthly") { // Deduct payment amount based on frequency
            balance -= payment.amount;
        } else if (payment.frequency == "biweekly") {
            balance -= payment.amount / 2;
        }
        std::cout << "Processed scheduled payment for: " << payment.purpose << ", Amount: $" << payment.amount << "\n\n";
    }
}

// Function to update user details
void User::updateDetails(const std::string& detailType, const std::string& newValue) {
    if (detailType == "name") { // Update details based on type
        name = newValue;
    } else if (detailType == "email") {
        email = newValue;
    } else if (detailType == "pin") {
        pin = newValue;
    } else {
        std::cout << "Invalid detail type.\n\n";
    }
}

void User::statements() const {// Function to display transaction statements for user
    std::cout << "Transaction statements for " << name << ":\n";
    for (const auto& payment : scheduledPayments) {
        std::cout << "Payment for: " << payment.purpose << ", Amount: $" << payment.amount << ", Frequency: " << payment.frequency << "\n";
    }
    std::cout << "\n";
}

// Function to schedule a payment for user
void User::schedulePayment(const std::string& purpose, double amount, const std::string& frequency) {
    ScheduledPayment payment{purpose, amount, frequency};// Create a scheduled payment object and add to list
    scheduledPayments.push_back(payment);
    std::cout << "Scheduled payment added successfully.\n\n";
}

void User::addCard(const Cards& card) { // Function to add a card to user's account
    cards.push_back(card);
    std::cout << "Card added successfully.\n\n";
}

void User::manageCards() { // Function to manage user's cards
    int choice;
    // Display card management menu
    do {
        std::cout << "1. Add Card\n2. Activate Card\n3. Deactivate Card\n4. Update Card Limit\n5. View Card Details\n6. Exit\nChoose an option: ";
        choice = getValidatedIntInput();
        switch (choice) {
            case 1: {
                std::string cardType, cardStart = "06/24", cardExpiry = "06/26";
                long long int cardNumber = std::stoll(generateRandomCardNumber());
                int cvv = generateRandomCVV();
                double limit = 1000.00;
                std::cout << "Enter card type (Debit or Credit): ";
                cardType = getValidatedStringInput();
                Cards card(cardType, cardNumber, cardStart, cardExpiry, cvv, limit);
                addCard(card);
                std::cout << "Card Number: " << cardNumber << "\n";
                std::cout << "CVV: " << cvv << "\n";
                std::cout << "Expiry Date: " << cardExpiry << "\n\n";
                break;
            }
            case 2: {
                long long int cardNumber;
                std::cout << "Enter card number to activate: ";
                cardNumber = getValidatedLongLongIntInput();
                for (auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.activateCard();
                        std::cout << "Card activated successfully.\n\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                long long int cardNumber;
                std::cout << "Enter card number to deactivate: ";
                cardNumber = getValidatedLongLongIntInput();
                for (auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.deactivateCard();
                        std::cout << "Card deactivated successfully.\n\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                long long int cardNumber;
                double newLimit;
                std::cout << "Enter card number to update limit: ";
                cardNumber = getValidatedLongLongIntInput();
                std::cout << "Enter new limit: ";
                newLimit = getValidatedDoubleInput();
                for (auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.updateLimit(newLimit);
                        std::cout << "Card limit updated successfully.\n\n";
                        break;
                    }
                }
                break;
            }
            case 5: {
                long long int cardNumber;
                std::cout << "Enter card number to view details: ";
                cardNumber = getValidatedLongLongIntInput();
                for (const auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.displayCardDetails();
                        break;
                    }
                }
                break;
            }
            case 6:
                std::cout << "Exiting card management...\n\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n\n";  // Print message for invalid option
        }
    } while (choice != 6); Repeat until user chooses to exit
}

} // namespace bankeasy
