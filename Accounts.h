#include "User.h" 
#include<string>
using namespace std ;

class Accounts {
    protected : 
    string name ; 
    string email ;
    double balance ;

    public : 
    virtual void deposit(double amount) ; 
    virtual void withdraw(double amount) ; 
    virtual void type() = 0 ;

    
} ; 

