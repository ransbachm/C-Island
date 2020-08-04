
#include <iostream>

int main() {

	try {
		for(int i=1; ; i*=2) {
			if(i<0) { // detect overflow
				throw "Overflow";
			}
		}
	} catch (const char *fehler) {
		std::cout << "Fehler : " << fehler << "\n";
	}
}
