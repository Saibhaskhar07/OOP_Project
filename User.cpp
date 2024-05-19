#include "User.h"
#include "StudentLoan.h"
#include "PersonalLoan.h"
#include <fstream>
#include <iostream>
#include <ctime>

namespace bankeasy {

User::User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, Loan* loan)
    : name(name), email(email), pin(pin), balance(loan ? loan->getAmount() : 0), accountType(accountType), loan(loan), transactionsFrozen(false) {}

User::~User() {
    delete loan;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPin() const {
    return pin;
}

double User::getBalance() const {
    return balance;
}

std::string User::getAccountType() const {
    return accountType;
}

void User::deposit(double amount) {
    if (transactionsFrozen) {
        std::cout << "Transactions are frozen for this account.\n\n";
        return;
    }
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited successfully.\n\n";
    }
}

void User::withdraw(double amount) {
    if (transactionsFrozen) {
        std::cout << "Transactions are frozen for this account.\n\n";
        return;
    }
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrawn successfully.\n\n";
    } else {
        std::cout << "Withdrawal failed. Insufficient balance.\n\n";
    }
}

void User::save(std::ofstream& out) const {
    out << name << '\n' << email << '\n' << pin << '\n' << balance << '\n' << accountType << '\n';
    if (loan) {
        out << loan->getLoanType() << '\n' << loan->getAmount() << '\n' << loan->getTenure() << '\n';
    } else {
        out << "No Loan\n";
    }
    out << transactionsFrozen << '\n';
    out << scheduledPayments.size() << '\n';
    for (const auto& payment : scheduledPayments) {
        out << payment.purpose << '\n' << payment.amount << '\n' << payment.frequency << '\n';
    }
    out << cards.size() << '\n';
    for (const auto& card : cards) {
        out << card.getType() << '\n' << card.getNumber() << '\n' << card.getStart() << '\n' << card.getExpiry() << '\n' << card.getCVV() << '\n' << card.getLimit() << '\n' << card.getStatus() << '\n';
    }
}

User User::load(std::ifstream& in) {
    std::string name, email, pin, accountType, loanType;
    double balance, amount;
    int tenure, numPayments, numCards;
    bool transactionsFrozen;
    std::getline(in, name);
    std::getline(in, email);
    std::getline(in, pin);
    in >> balance;
    in.ignore();
    std::getline(in, accountType);
    std::getline(in, loanType);
    if (loanType != "No Loan") {
        in >> amount >> tenure;
        in.ignore();
        Loan* loan = nullptr;
        if (loanType == "Student Loan") {
            std::string course, placeOfStudy;
            std::getline(in, course);
            std::getline(in, placeOfStudy);
            loan = new StudentLoan(amount, tenure, course, placeOfStudy); // Correct constructor usage
        } else if (loanType == "Personal Loan") {
            loan = new PersonalLoan(amount, tenure);
        }
        User user(name, email, pin, accountType, loan);
        user.balance = balance;
        in >> transactionsFrozen;
        user.transactionsFrozen = transactionsFrozen;
        in.ignore();
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
        in >> numCards;
        in.ignore();
        for (int i = 0; i < numCards; ++i) {
            std::string cardType, cardStart, cardExpiry;
            long int cardNumber;
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
        return user;
    }
    User user(name, email, pin, accountType);
    user.balance = balance;
    in >> transactionsFrozen;
    user.transactionsFrozen = transactionsFrozen;
    in.ignore();
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
    in >> numCards;
    in.ignore();
    for (int i = 0; i < numCards; ++i) {
        std::string cardType, cardStart, cardExpiry;
        long int cardNumber;
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
    return user;
}

void User::changeInterestRate(double newRate) {
    if (loan) {
        loan->changeInterestRate(newRate);
    }
}

void User::freezeTransactions() {
    transactionsFrozen = true;
}

void User::unfreezeTransactions() {
    transactionsFrozen = false;
}

void User::updateLoginDetails(const std::string& newEmail, const std::string& newPin) {
    email = newEmail;
    pin = newPin;
}

void User::processScheduledPayments() {
    if (scheduledPayments.empty()) {
        return;
    }
    std::time_t now = std::time(nullptr);
    for (const auto& payment : scheduledPayments) {
        if (payment.frequency == "monthly") {
            balance -= payment.amount;
        } else if (payment.frequency == "biweekly") {
            balance -= payment.amount / 2;
        }
        std::cout << "Processed scheduled payment for: " << payment.purpose << ", Amount: $" << payment.amount << "\n\n";
    }
}

void User::updateDetails(const std::string& detailType, const std::string& newValue) {
    if (detailType == "name") {
        name = newValue;
    } else if (detailType == "email") {
        email = newValue;
    } else if (detailType == "pin") {
        pin = newValue;
    } else {
        std::cout << "Invalid detail type.\n\n";
    }
}

void User::statements() const {
    std::cout << "Transaction statements for " << name << ":\n";
    for (const auto& payment : scheduledPayments) {
        std::cout << "Payment for: " << payment.purpose << ", Amount: $" << payment.amount << ", Frequency: " << payment.frequency << "\n";
    }
    std::cout << "\n";
}

void User::schedulePayment(const std::string& purpose, double amount, const std::string& frequency) {
    ScheduledPayment payment{purpose, amount, frequency};
    scheduledPayments.push_back(payment);
    std::cout << "Scheduled payment added successfully.\n\n";
}

void User::addCard(const Cards& card) {
    cards.push_back(card);
    std::cout << "Card added successfully.\n\n";
}

void User::manageCards() {
    int choice;
    do {
        std::cout << "1. Add Card\n2. Activate Card\n3. Deactivate Card\n4. Update Card Limit\n5. View Card Details\n6. Exit\nChoose an option: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string cardType, cardStart, cardExpiry;
                long int cardNumber;
                int cvv;
                double limit;
                std::cout << "Enter card type: ";
                std::cin >> cardType;
                std::cout << "Enter card number: ";
                std::cin >> cardNumber;
                std::cout << "Enter card start date: ";
                std::cin >> cardStart;
                std::cout << "Enter card expiry date: ";
                std::cin >> cardExpiry;
                std::cout << "Enter CVV: ";
                std::cin >> cvv;
                std::cout << "Enter card limit: ";
                std::cin >> limit;
                Cards card(cardType, cardNumber, cardStart, cardExpiry, cvv, limit);
                addCard(card);
                break;
            }
            case 2: {
                long int cardNumber;
                std::cout << "Enter card number to activate: ";
                std::cin >> cardNumber;
                for (auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.activateCard();
                        break;
                    }
                }
                break;
            }
            case 3: {
                long int cardNumber;
                std::cout << "Enter card number to deactivate: ";
                std::cin >> cardNumber;
                for (auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.deactivateCard();
                        break;
                    }
                }
                break;
            }
            case 4: {
                long int cardNumber;
                double newLimit;
                std::cout << "Enter card number to update limit: ";
                std::cin >> cardNumber;
                std::cout << "Enter new limit: ";
                std::cin >> newLimit;
                for (auto& card : cards) {
                    if (card.getNumber() == cardNumber) {
                        card.updateLimit(newLimit);
                        break;
                    }
                }
                break;
            }
            case 5: {
                long int cardNumber;
                std::cout << "Enter card number to view details: ";
                std::cin >> cardNumber;
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
                std::cout << "Invalid option. Please try again.\n\n";
        }
    } while (choice != 6);
}

} // namespace bankeasy
