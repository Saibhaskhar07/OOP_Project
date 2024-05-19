#include "StudentLoan.h"
#include <iostream>

namespace bankeasy {

StudentLoan::StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy)
    : Loan("Student Loan", amount, tenure), course(course), placeOfStudy(placeOfStudy) {}

void StudentLoan::showDocumentation() const {
    std::cout << "Required documents for Student Loan:\n";
    std::cout << "- COE\n";
    std::cout << "- Proof of Identity\n";
    std::cout << "- Proof of Residence\n";
    std::cout << "- ITR for 2 years\n";
    std::cout << "- Place of Study\n";
}

std::string StudentLoan::getCourse() const {
    return course;
}

std::string StudentLoan::getPlaceOfStudy() const {
    return placeOfStudy;
}

} // namespace bankeasy
