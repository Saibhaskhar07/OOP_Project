#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <iostream>

namespace BankEasy {

class Account {
public:
    virtual void type() = 0;  // Pure virtual function
    virtual ~Account() = default;
};

}  // namespace BankEasy

#endif  // ACCOUNTS_H
