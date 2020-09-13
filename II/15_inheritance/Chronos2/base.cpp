#include "base.hpp"

std::ostream& base::print(std::ostream& os) const {
    return os << value_;
}