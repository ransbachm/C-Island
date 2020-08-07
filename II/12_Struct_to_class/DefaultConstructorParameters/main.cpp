

#include <iostream>
#include <string>
#include <ostream>

using std::string; using std::cout;

class Person {
	string name_;
	int age_;
	string town_;

public:
	std::ostream& print(std::ostream &os);
	Person(string name = "n/a", int age = -1, string town = "n/a")
		: name_(name), age_(age), town_(town) {}
};

std::ostream& Person::print(std::ostream &os) {
	return os << name_ << " (" << age_ << ") " << "aus " << town_;
}

std::ostream& operator<<(std::ostream &os, Person p) {
	return p.print(os);
}

int main() {
	Person esdeath = {"Esdeath"};
	cout << esdeath << '\n';
}

