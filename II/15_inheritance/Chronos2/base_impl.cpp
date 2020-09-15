#include <iostream>
#include "base_impl.hpp"

using chronos2::date; using chronos2::year;

std::ostream& date::print(std::ostream& os) const {
    return os << year_ << "-" << month_ << "-" << day_;
}

std::ostream& operator<<(std::ostream& os, date date) {
    return date.print(os);
}

date year::getLastDay() const {
    return date{year{value_}, month{12}, day{31}};
}