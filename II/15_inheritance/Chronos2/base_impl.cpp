#include <iostream>
#include "base_impl.hpp"

using namespace chronos2;

std::ostream& date::print(std::ostream& os) const {
    return os << year_ << "-" << month_ << "-" << day_;
}

std::ostream& operator<<(std::ostream& os, date date) {
    return date.print(os);
}