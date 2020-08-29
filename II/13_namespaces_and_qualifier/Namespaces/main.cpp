

#include <iostream>

namespace plant {
	class Baum { // define class
		std::string name_;
	public:
		explicit Baum(const std::string& name) : name_{name} {}
		void print(std::ostream& os) const {os<<name_;}
	};

	std::ostream& operator<<(std::ostream& os, const Baum& arg) { // override operaor for baum class
		arg.print(os); return os;
	}

	using NadelBaum = Baum; // reserve for future use
	using LaubBaum = Baum; // reserve for future use

	namespace beispielnamen { // internal namespace
		std::string eicheName = "Eiche";
		std::string bucheName = "Buche";
		std::string tanneName = "Tanne";
	}
}

int main() {
	using namespace plant::beispielnamen;
	plant::NadelBaum tanne {tanneName}; // using inner namespace, not outer
	plant::LaubBaum eiche {eicheName}; // taken from 'beispielnamen'
	tanne.print(std::cout); std::cout << "\n"; // can just be done
	//cout << tanne; // would not work
	using plant::operator<<; // use operator
	std::cout << eiche << "\n";
}
