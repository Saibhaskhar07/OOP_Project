#ifndef STUDENT_LOAN_H
#define STUDENT_LOAN_H

#include "Loan.h"
#include <string>
using namespace std;

class Student_Loan : public Loan {
protected:
    long int Student_Loan_Num;
    string Student_Name;
    string Relationship;
    string Place;
    string Course;

public:
    Student_Loan(long int s_no, int tenure, const string& course, const string& place, double reqAmt);

    void set_Student_Name(const string& name);
    void set_Relationship(const string& relation);
    void set_course(const string& course);
    void set_place(const string& place);
    void displayStudent_Loan_Docs();

    string get_Student_Name() const;
    string get_Relationship() const;
    string get_course() const;
    string get_place() const;
    double get_interest() const;

    void displayDocuments() const override;
};

#endif // STUDENT_LOAN_H
