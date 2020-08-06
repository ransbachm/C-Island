

#include <string>
#include <iostream>
using std::string; using std::cout;

struct Person {
	string name_;
	int alter_;
	string ort_;
}; // dont forget

void drucke(Person p) {
	cout << p.name_ << " (" << p.alter_ << ") aus "
		<< p.ort_ << "\n";
}

int main() {
	Person otto {"Otto", 45, "Kassel"}; // c++ initialisation
	drucke(otto);
}
