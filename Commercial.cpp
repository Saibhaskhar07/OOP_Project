#include "Commercial.h"

namespace bankeasy {

Commercial::Commercial() : Accounts() {}

std::string Commercial::type() const {
    return "Commercial";
}

} // namespace bankeasy
