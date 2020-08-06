#include <string>
#include <fstream>
#include <sstream>
#include <iostream> // cout, ofstream, probable ostringstream


using std::cout; using std::string;

struct Person {
	string name_;
	int alter_;
	string ort_;
	void drucke(std::ostream& os);
};

void Person::drucke(std::ostream& os) { // take ostream as referenct, (&), dont copy it!
	os << name_ << " (" << alter_ << ") aus " << ort_;
}
int main() {
	Person karl {"Karl", 12, "Stetten"};
	karl.drucke(cout);
	cout << "\n";

	std::ofstream datei {"personen.txt"};
	karl.drucke(datei);

	std::ostringstream oss {};
	karl.drucke(oss);
	cout << "Via std::ostringstream : " << oss.str() << "\n";
}
