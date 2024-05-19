#include "Loan.h"
#include <cmath>
#include <iostream>

namespace bankeasy {

Loan::Loan(const std::string& loanType, double amount, int tenure)
    : loanType(loanType), amount(amount), tenure(tenure), interestRate(0) {}

double Loan::calculateEMI(double interestRate) const {
    double monthlyInterestRate = interestRate / (12 * 100);
    return (amount * monthlyInterestRate * std::pow(1 + monthlyInterestRate, tenure)) / (std::pow(1 + monthlyInterestRate, tenure) - 1);
}

std::string Loan::getLoanType() const {
    return loanType;
}

double Loan::getAmount() const {
    return amount;
}

int Loan::getTenure() const {
    return tenure;
}

void Loan::changeInterestRate(double newRate) {
    interestRate = newRate;
}

} // namespace bankeasy
