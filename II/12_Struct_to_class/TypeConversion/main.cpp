#include <iostream>

class Month {
	int value_;
public:
	explicit Month(int m) : value_(m) {}
	Month& advance(const Month& other);
	std::ostream& print(std::ostream& os) const;
	bool equals(const Month& other) const;
	bool less_then(const Month& other) const;
};

std::ostream& Month::print(std::ostream& os) const { // const method -> can't modify own object
	return os << value_;
}

std::ostream& operator<<(std::ostream& os, Month& month) {
	return month.print(os);
}

Month& Month::advance(const Month& other) {
	this->value_ += other.value_; // with thisdot
	return *this;
}

bool Month::equals(const Month& other) const {
	return value_ == other.value_; // without thisdot
}

bool Month::less_then(const Month& other) const {
	return value_ < other.value_;
}


int main() {
	Month month {8};
	month.advance(Month{1});
	std::cout << month << "\n";
}
