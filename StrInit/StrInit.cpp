
#include <string>
#include <iostream>

int main() {

	using std::cout;

	// do
	std::string name; // uses std constructor
	std::string name2 {}; // explicitly uses std constructor

	// don't
	std::string name3 = ""; // should use copy constructor
	// std::string name4 (); // you can't do that, because of advanced things
	std::string name4 = ("");

	std::string sp = " | ";

	std::string strS [] = {name, name2, name3, name4};

	for(int i=0; i<sizeof(strS) / sizeof(std::string); ++i) {
		cout << strS[i].length() << sp;
	}
}
