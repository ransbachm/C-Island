#include <iostream>
#include "base_impl.hpp"


std::ostream& chronos2::date::print(std::ostream& os) const {
    return os << year_ << "-" << month_ << "-" << day_;
}

std::ostream& operator<<(std::ostream& os, chronos2::date date) {
    return date.print(os);
}