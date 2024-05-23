#ifndef PERSONALLOAN_H
#define PERSONALLOAN_H

#include "Loan.h"
#include <string>

namespace bankeasy { // Define namespace bankeasy

class PersonalLoan : public Loan { // Define Personal Loan class from Loan
public:
    PersonalLoan(double amount, int tenure, const std::string& purpose); // Get Loan parameters
    std::string getLoanType() const override;
    std::string getPurpose() const;
    void changeInterestRate(double newRate) override;
    void displayRequiredDocuments() const override; // Display loan info
    void calculateEMI() const override; // Calculate EMI

private:
    std::string purpose;
};

} // namespace bankeasy

#endif // PERSONALLOAN_H
