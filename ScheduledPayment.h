#ifndef SCHEDULEDPAYMENT_H
#define SCHEDULEDPAYMENT_H

#include <string>

namespace bankeasy { // Define namespace bankeas

struct ScheduledPayment { // Define ScheduledPayment structure
    std::string purpose; // Purpose for the scheduled payments
    double amount; // Amount of scheduled payment
    std::string frequency; // Frequency/how often to pay it
};

} // namespace bankeasy

#endif // SCHEDULEDPAYMENT_H

