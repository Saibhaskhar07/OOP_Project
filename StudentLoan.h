#ifndef STUDENTLOAN_H
#define STUDENTLOAN_H

#include "Loan.h"

namespace bankeasy {

class StudentLoan : public Loan {
public:
    StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy);
    std::string getLoanType() const override;
    void displayRequiredDocuments() const override;
    void calculateEMI() const override;

private:
    std::string course;
    std::string placeOfStudy;
};

} // namespace bankeasy

#endif // STUDENTLOAN_H
