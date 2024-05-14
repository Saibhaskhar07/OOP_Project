#include "Personal_Loan.h"
#include "Student_Loan.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<Loan> loan;
    string choice;

    cout << "Welcome to BankEasy Loan Services" << endl;
    cout << "Please choose the type of loan you need:" << endl;
    cout << "1: Personal Loan" << endl;
    cout << "2: Student Loan" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == "1") {
        long int p_no;
        int tenure;
        string purpose;
        double reqAmt;

        cout << "Enter personal loan number (numeric ID): ";
        cin >> p_no;
        cout << "Enter the purpose of the loan: ";
        cin.ignore();
        getline(cin, purpose);
        cout << "Enter the loan amount required: ";
        cin >> reqAmt;
        cout << "Enter the tenure of the loan in years: ";
        cin >> tenure;

        loan = unique_ptr<Personal_Loan>(new Personal_Loan(p_no, tenure, purpose, reqAmt));
        cout << "You have selected a Personal Loan." << endl;
    } else if (choice == "2") {
        long int s_no;
        string studentName, course, place;
        int tenure;
        double reqAmt;

        cout << "Enter student loan number (numeric ID): ";
        cin >> s_no;
        cout << "Enter the student's name: ";
        cin.ignore();
        getline(cin, studentName);
        cout << "Enter the course of study: ";
        getline(cin, course);
        cout << "Enter the place of study: ";
        getline(cin, place);
        cout << "Enter the loan amount required: ";
        cin >> reqAmt;
        cout << "Enter the tenure of the loan in years: ";
        cin >> tenure;

        loan = unique_ptr<Student_Loan>(new Student_Loan(s_no, tenure, course, place, reqAmt));
        cout << "You have selected a Student Loan." << endl;
    } else {
        cout << "Invalid choice entered. Please run the program again." << endl;
        return 1; // Exiting the program due to invalid input
    }

    loan->displayDocuments();
    
    return 0;
}
