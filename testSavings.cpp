#include <iostream>
#include "Savings.h"

using namespace std;

void displayMenu() {
    cout << "\nBanking Menu:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Schedule Payment\n";
    cout << "4. View Scheduled Payments\n";
    cout << "5. Exit\n";
}

int main() {
    // Create a savings account
    Savings savings_account;

    // Display initial balance
    cout << "Initial balance in savings account: $" << savings_account.get_balance() << endl;

    int choice;
    do {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Deposit
                double depositAmount;
                cout << "Enter amount to deposit into savings account: ";
                cin >> depositAmount;
                savings_account.deposit(depositAmount);
                cout << "Balance in savings account after deposit: $" << savings_account.get_balance() << endl;
                break;
            }
            case 2: {
                // Withdraw
                double withdrawAmount;
                cout << "Enter amount to withdraw from savings account: ";
                cin >> withdrawAmount;
                savings_account.withdraw(withdrawAmount);
                cout << "Balance in savings account after withdrawal: $" << savings_account.get_balance() << endl;
                break;
            }
            case 3: {
                // Schedule Payment
                string payment;
                double payableAmount;
                savings_account.scheduledPayment(payment, payableAmount);
                break;
            }
            case 4: {
                // View Scheduled Payments
                savings_account.viewScheduledPayments();
                break;
            }
            case 5: {
                // Exit
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}