#include "Student_Loan.h"
using namespace std;

Student_Loan::Student_Loan(long int s_no, int tenure, const string& course, const string& place, double reqAmt)
: Loan(), Student_Loan_Num(s_no), Student_Name(), Relationship(), Place(place), Course(course) {
    set_tenure(tenure);
    set_required_amount(reqAmt);
    interest = 12.8; // Assuming a fixed interest rate for simplicity
}

void Student_Loan::set_Student_Name(const string& name) {
    Student_Name = name;
}

void Student_Loan::set_Relationship(const string& relation) {
    Relationship = relation;
}

void Student_Loan::set_course(const string& course) {
    Course = course;
}

void Student_Loan::set_place(const string& place) {
    Place = place;
}

void Student_Loan::displayStudent_Loan_Docs() {
    cout << "Documents required:\n";
    cout << "1. 2 Passport size photographs of both the student and the sponsor\n";
    cout << "2. 2 years Income Tax returns of the sponsor\n";
    cout << "3. 6 months Payslip of the sponsor\n";
    cout << "4. Proof of Identity of both student and sponsor\n";
    cout << "5. Proof of Address of both sponsor\n";
    cout << "6. 10th Marksheet of the Student\n";
    cout << "7. 12th Marksheet of the Student\n";
    cout << "8. Offer Letter issued by University\n";
}

string Student_Loan::get_Student_Name() const {
    return Student_Name;
}

string Student_Loan::get_Relationship() const {
    return Relationship;
}

string Student_Loan::get_course() const {
    return Course;
}

string Student_Loan::get_place() const {
    return Place;
}

double Student_Loan::get_interest() const {
    return 12.8;
}

void Student_Loan::displayDocuments() const {
    cout << "The details of your Student loan are as follows:\n";
    cout << "Student Name: " << get_Student_Name() << endl;
    cout << "Relation to the Student: " << get_Relationship() << endl;
    cout << "Course: " << get_course() << endl;
    cout << "Place: " << get_place() << endl;
    cout << "Tenure: " << get_tenure() << endl;
    cout << "Interest Rate: " << get_interest() << endl;
    cout << "Required Amount: " << get_required_amount() << endl;
}
