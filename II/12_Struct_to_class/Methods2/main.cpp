#include <string>
#include <fstream>
#include <sstream>
#include <iostream> // cout, ofstream, probable ostringstream


using std::cout; using std::string;

struct Person {
	string name_;
	int alter_;
	string ort_;

	std::ostream& drucke(std::ostream& os);
};

std::ostream& Person::drucke(std::ostream& os) { // take ostream as referenct, (&), dont copy it!
	return os << name_ << " (" << alter_ << ") aus " << ort_;
}

std::ostream& operator<<(std::ostream& os, Person p) {
	return p.drucke(os); // give "drucke" the os to write to and then return it futher use
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

	cout << "Now I will use the \'<<\' operator on my own struct: " << karl << ".\nSuccess\n";
}
