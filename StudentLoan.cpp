#include "StudentLoan.h"
#include <iostream>

namespace bankeasy {

StudentLoan::StudentLoan(double amount, int tenure)
    : Loan("Student Loan", amount, tenure) {}

void StudentLoan::showDocumentation() const {
    std::cout << "Required documents for Student Loan:\n";
    std::cout << "- COE\n";
    std::cout << "- Proof of Identity\n";
    std::cout << "- Proof of Residence\n";
    std::cout << "- ITR for 2 years\n";
    std::cout << "- Place of Study\n";
}

} // namespace bankeasy
