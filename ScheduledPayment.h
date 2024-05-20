#ifndef SCHEDULEDPAYMENT_H
#define SCHEDULEDPAYMENT_H

#include <string>

namespace bankeasy {

struct ScheduledPayment {
    std::string purpose;
    double amount;
    std::string frequency;
};

} // namespace bankeasy

#endif // SCHEDULEDPAYMENT_H
