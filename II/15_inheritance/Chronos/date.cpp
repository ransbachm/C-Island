
#include <iostream>
#include <iomanip>

#include "value.hpp"


using std::ostream;
using namespace chronos;

ostream& Date::print(ostream& os) const {
	return os << year_ << "-" << month_ << "-" << day_;
}

ostream& operator<<(ostream& os, Date d) {
	return d.print(os);
}


