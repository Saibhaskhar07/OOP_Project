#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

class Savings : public Account {
protected:
    struct Payment {
        string description;
        double amount;
        string frequency;
        string when;
    };

    double balance;
    Payment* scheduled_payments;
    int num_payments;

public:
    Savings();
    ~Savings(); 
    void deposit(double depositAmount);
    void withdraw(double withdrawAmount);
    void scheduledPayment(string payment, double payableAmount);
    void viewScheduledPayments();
    double get_balance();
};

#endif
