#include "Loan.h"
#include <iostream>
#include <algorithm>

void Loan::applyForLoan() {
    std::cout << "Loan Application Process started, Please tell what kind of a loan would you want: Personal or Student." << std::endl;
}

double Loan::calculateMonthlyInstallments(double principal, double monthlyInterestRate, int tenureMonths) {
    return (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, tenureMonths))
                 / (pow(1 + monthlyInterestRate, tenureMonths) - 1);
}

void Loan::submitDocumentation(const std::string& ans) {
    std::cout << "Do you want to submit your documents to the bank? " << std::endl;
}

void Loan::type(const std::string& p) {
    std::string input = p;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "personal") {
        Loan_type = "Personal";
    } else {
        Loan_type = "Invalid";
    }

    std::cout << "Loan type set to " << Loan_type << "." << std::endl;
}
