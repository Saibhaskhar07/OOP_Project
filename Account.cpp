#include <iostream>
#include "Account.h" 
using namespace std ;

Account::Account()
{
    this->name = " " ;
    this->email = " " ;
    this->age = 0 ;
    this->accNo = 0 ; 
    this->transactions = " " ; 
}

void Account::set_name(string Name)
{
    this->name = Name ;
}

void Account::set_email(string Email)
{
    this->email = Email ;
}

void Account::set_age(int Age)
{
    this->age = Age ;
}

string Account::get_name()
{
    return this->name ;
}

string Account::get_email()
{
    return this->email ;
}

int Account::get_age()
{
    return this->age ;
}
