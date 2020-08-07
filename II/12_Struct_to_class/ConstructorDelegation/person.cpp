
#include <iostream>
#include <string>

using std::string;


struct Person {
	string name_;
	int alter_;
	string ort_;

	// Constructors are declard and implemented, this shoudn't be neccessary
	// but can be cleaner
	Person(string n, int a, string o) // 'receiving' constructor
		: name_(n), alter_(a), ort_(o) {std::cout << "Receiveing constructor was called";}

	Person() : Person{"Kein name", -1, "kein ort"} {} // delegating constructor
	Person(string n, int a) : Person{n, a, "kein ort"} {}
	Person(string n) : Person{n, -1, "kein Ort"} {}
};

