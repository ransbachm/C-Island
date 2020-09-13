#include "base.hpp"

std::ostream& Base::print(std::ostream& os) const {
    os << value_;
}