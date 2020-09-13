#include <iostream>
#include <iomanip>

using std::ostream; using std::setfill; using std::setw;

class Value {
protected:
	int value_;
	const unsigned width_;
	Value(int v, unsigned w)
		: value_{v}, width_{w} {}
public:
	ostream& print(ostream& os) const;
};

ostream& operator<<(ostream& os, const Value& val) {
	return val.print(os);
}

ostream& Value::print(ostream& os) const {
	return os << setfill('0') << setw(width_) << value_;
}
