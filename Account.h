#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream> 
#include <string>
using namespace std ;


class Account{
    // Attributes required for account creation
    protected :
        string name ;
        string email ;
        int age ;
        long int accNo ;
        string transactions ;

    public : 
        Account() ; 
        // work on paramaterized constructor ! 
        void set_name(string Name) ;
        void set_email(string Email) ;
        void set_age(int Age) ;
        string get_name() ;
        string get_email() ; 
        int get_age() ; 




} ;
#endif