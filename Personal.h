#ifndef PERSONAL_H
#define PERSONAL_H

#include <string>
#include <iostream>
#include "Accounts.h"
#include "Loan.h"

namespace bankeasy {

class Personal : public Accounts {
public:
    Personal();
    std::string type() const override;
    static std::string chooseAccountType(Loan*& loan);

private:
    struct ScheduledPayment {
        std::string purpose;
        double amount;
        std::string frequency;
    };
    std::vector<ScheduledPayment> scheduledPayments;
};

} // namespace bankeasy

#endif // PERSONAL_H
