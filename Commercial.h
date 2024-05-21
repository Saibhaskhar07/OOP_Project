#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Accounts.h"
#include <string>

namespace bankeasy {

class Commercial : public Accounts {
public:
    Commercial();
    std::string type() const override;
    void bookAppointment() const;

private:
    std::string date;
    std::string time;
};

} // namespace bankeasy

#endif // COMMERCIAL_H
