#ifndef PERSONALLOAN_H
#define PERSONALLOAN_H

#include "Loan.h"
#include <string>

namespace bankeasy {

class PersonalLoan : public Loan {
public:
    PersonalLoan(double amount, int tenure, const std::string& purpose);
    std::string getLoanType() const override;
    std::string getPurpose() const;
    void changeInterestRate(double newRate) override;
    void displayRequiredDocuments() const override;
    void calculateEMI() const override;

private:
    std::string purpose;
};

} // namespace bankeasy

#endif // PERSONALLOAN_H