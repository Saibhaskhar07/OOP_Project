#ifndef PERSONAL_H
#define PERSONAL_H

#include "Accounts.h"
#include "Loan.h"
#include <string>

namespace bankeasy {

class Personal : public Accounts {
public:
    Personal();
    std::string type() const override;
    static std::string chooseAccountType(Loan*& loan);

private:
    std::string accountType;
};

} // namespace bankeasy

#endif // PERSONAL_H
