#include "Loan.h"

namespace bankeasy { // Define namespace bankeasy

Loan::Loan(double amount, int tenure)
    : amount(amount), tenure(tenure), interestRate(0.0) {} // Constructor initializes the loan information

double Loan::getAmount() const {
    return amount; // Get Loan amount
}

int Loan::getTenure() const {
    return tenure; // Get the tenure of the loan
}

} // end of the amespace bankeasy