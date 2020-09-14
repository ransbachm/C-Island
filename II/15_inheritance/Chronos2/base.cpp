#include "base.hpp"

std::ostream& base::print(std::ostream& os) const {
    return os << value_;
}

std::ostream& operator<<(std::ostream& os, base base) {
    return base.print(os);
}