#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Loan.h"
#include "Cards.h"
#include "ScheduledPayment.h"
#include "Utils.h"

namespace bankeasy {

class User {
public:
    User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, Loan* loan = nullptr);
    ~User();

    std::string getName() const;
    std::string getEmail() const;
    std::string getPin() const;
    double getBalance() const;
    std::string getAccountType() const;

    void deposit(double amount);
    void withdraw(double amount);
    void save(std::ofstream& out) const;
    static User load(std::ifstream& in);
    void changeInterestRate(double newRate);
    void freezeTransactions();
    void unfreezeTransactions();
    void updateLoginDetails(const std::string& newEmail, const std::string& newPin);
    void processScheduledPayments();
    void updateDetails(const std::string& detailType, const std::string& newValue);
    void statements() const;
    void schedulePayment(const std::string& purpose, double amount, const std::string& frequency);
    void addCard(const Cards& card);
    void manageCards();

private:
    std::string name;
    std::string email;
    std::string pin;
    double balance;
    std::string accountType;
    Loan* loan;
    bool transactionsFrozen;
    std::vector<ScheduledPayment> scheduledPayments;
    std::vector<Cards> cards;
};

} // namespace bankeasy

#endif // USER_H
