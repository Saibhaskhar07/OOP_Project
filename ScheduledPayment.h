#ifndef SCHEDULEDPAYMENT_H // Header guard to prevent multiple inclusion
#define SCHEDULEDPAYMENT_H

#include <string> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

struct ScheduledPayment { // Declare struct ScheduledPayment
    std::string purpose; // Member variable for payment purpose
    double amount; // Member variable for payment amount
    std::string frequency; // Member variable for payment frequency
};

} // End namespace bankeasy

#endif // End of header guard and file
