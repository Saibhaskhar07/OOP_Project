#include "Loan.h"
#include <iostream>

namespace bankeasy {

Loan::Loan(double amount, int tenure)
    : amount(amount), tenure(tenure), interestRate(0.0) {}

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