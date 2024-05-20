#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Accounts.h"

namespace bankeasy {

class Commercial : public Accounts {
public:
    Commercial();
    std::string type() const override;
    void bookAppointment();
};

} // namespace bankeasy

#endif // COMMERCIAL_H
