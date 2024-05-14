#include "Savings.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Savings::Savings() : Account() {
    // Seed the random number generator
    srand(time(0));
    // Generate a random initial balance between 100 and 100,000
    balance = rand() % 99901 + 100; 
    scheduled_payments = nullptr; 
    num_payments = 0;
}

Savings::~Savings() {
    delete[] scheduled_payments; 
}

void Savings::deposit(double depositAmount) {
    balance += depositAmount;
}

void Savings::withdraw(double withdrawAmount) {
    balance -= withdrawAmount;
}

void Savings::scheduledPayment(string payment, double payableAmount) {
    cout << "What would you like to schedule a payment for? ";
    cin >> payment;

    cout << "How much would you like to schedule to be paid? ";
    cin >> payableAmount;

    // Determine frequency
    string frequency;
    cout << "Would you like to schedule the payment weekly or monthly? ";
    cin >> frequency;

    string when;
    if (frequency == "weekly") {
        cout << "When would you like the payment to occur each week? ";
        cin >> when;
    } else if (frequency == "monthly") {
        cout << "When would you like the payment to occur each month? ";
        cin >> when;
    } else {
        cout << "Invalid frequency entered. Payment not scheduled.\n";
        return;
    }

    // Allocate memory for the new array of payments
    Payment* new_payments = new Payment[num_payments + 1];

    // Copy existing payments to the new array
    for (int i = 0; i < num_payments; ++i) {
        new_payments[i] = scheduled_payments[i];
    }

    // Add the new payment at the end of the array
    new_payments[num_payments].description = payment;
    new_payments[num_payments].amount = payableAmount;
    new_payments[num_payments].frequency = frequency;
    new_payments[num_payments].when = when;

    // Free memory for the old array
    delete[] scheduled_payments;

    // Update pointer to point to the new array
    scheduled_payments = new_payments;

    // Increment the number of payments
    num_payments++;
}

void Savings::viewScheduledPayments() {
    if (num_payments == 0) {
        cout << "No scheduled payments.\n";
        return;
    }

    cout << "Scheduled Payments:\n";
    for (int i = 0; i < num_payments; ++i) {
        cout << i + 1 << ". " << scheduled_payments[i].description << ": $" << scheduled_payments[i].amount 
             << " (" << scheduled_payments[i].frequency << ", " << scheduled_payments[i].when << ")" << endl;
    }
}

double Savings::get_balance() {
    return balance;
}
