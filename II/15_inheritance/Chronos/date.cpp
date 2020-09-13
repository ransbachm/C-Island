#include "date.hpp"

using std::ostream;

ostream& Date::print(ostream& os) const {
	return os << year_ << "-" << month_ << "-" << day_;
}

ostream& operator<<(ostream& os, Date d) {
	return d.print(os);
}


