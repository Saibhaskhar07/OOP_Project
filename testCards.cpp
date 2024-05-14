#include <iostream>
#include "DebitCard.h"

using namespace std;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Issue Debit Card\n";
    cout << "2. View Card Details\n";
    cout << "3. Exit\n";
}

int main() {
    srand(time(0)); // Seed the random number generator

    Account account;
    DebitCard debitCard;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                debitCard.issueDebitCard(account);
                cout << "Debit card issued.\n";
                break;
            case 2:
                if (debitCard.getCardNumber().empty()) {
                    cout << "No debit card issued yet.\n";
                } else {
                    cout << "Debit Card Information:\n";
                    cout << "Card Number: " << debitCard.getCardNumber() << endl;
                    cout << "CVV: " << debitCard.getCVV() << endl;
                    cout << "Expiration Date: " << debitCard.getExpirationDate() << endl;
                }
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
