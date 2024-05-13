#include <iostream>
#include "Personal.h"
#include <vector>

void displayAllAccountDetails(const std::vector<Account*>& accounts) {
    for (const Account* acc : accounts) {
        acc->displayAccountDetails();
        std::cout << std::endl;  // Adding a newline for better readability between accounts
    }
}

int main() {
    Personal a; // Now correctly constructs a Personal object

    a.set_name("Saibhaskhar");
    a.set_email("saibhaskharr@gmail.com");
    a.set_age(19);

    a.applyForLoan();
    a.type("Personal");

    std::vector<Account*> accounts;
    accounts.push_back(&a);
    displayAllAccountDetails(accounts);

    std::cout << a.get_name() << std::endl;
    std::cout << a.get_age() << std::endl;
    std::cout << a.get_email() << std::endl;

    return 0;
}
