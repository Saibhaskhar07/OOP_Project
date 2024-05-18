#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <string>
#include <iostream>
#include "Accounts.h"

class Commercial : public Accounts {
public:
    Commercial();
    std::string type() const override;
};

#endif // COMMERCIAL_H
