#ifndef STUDENTLOAN_H
#define STUDENTLOAN_H

#include "Loan.h" // Include base class header file
#include <string>

namespace bankeasy {

class StudentLoan : public Loan { // Declare StudentLoan class inheriting from Loan
public:
    StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy); // Constructor
    std::string getLoanType() const override; // Override base class method to get loan type
    std::string getCourse() const; // Get course of study
    std::string getPlaceOfStudy() const; // Get place of study
    void changeInterestRate(double newRate) override; // Override base class method to change interest rate
    void displayRequiredDocuments() const override; // Override base class method to display required documents
    void calculateEMI() const override; // Override base class method to calculate EMI

private:
    std::string course; // Member variable for course of study
    std::string placeOfStudy; // Member variable for place of study
};

} // namespace bankeasy

#endif // STUDENTLOAN_H
