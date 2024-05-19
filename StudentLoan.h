#ifndef STUDENT_LOAN_H
#define STUDENT_LOAN_H

#include "Loan.h"

namespace bankeasy {

class StudentLoan : public Loan {
public:
    StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy);
    void showDocumentation() const override;
    std::string getCourse() const;
    std::string getPlaceOfStudy() const;

private:
    std::string course;
    std::string placeOfStudy;
};

} // namespace bankeasy

#endif // STUDENT_LOAN_H
