#include "PersonalLoan.h"
#include <iostream>

namespace bankeasy {

PersonalLoan::PersonalLoan(double amount, int tenure)
    : Loan("Personal Loan", amount, tenure) {}

void PersonalLoan::showDocumentation() const {
    std::cout << "Required documents for Personal Loan:\n";
    std::cout << "- Purpose\n";
    std::cout << "- Proof of Identity\n";
    std::cout << "- Proof of Residence\n";
    std::cout << "- ITR for 2 years\n";
}

} // namespace bankeasy
