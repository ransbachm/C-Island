


#include <iostream>

int main(int argc, char **argv) {
	int wert = -1;
	if(argc == 2) 
		wert = (int) strtol(argv[1], NULL, 10);
	else
		std::cin >> wert;
	int primeCounter = 0;
	std::cout << "Teiler von " << wert << " sind:\n";
	for(int i=1; i < wert; i++) {
		if(wert % i == 0) {
			std::cout << i << "\n";
			primeCounter++;
		}
	}

	if(primeCounter < 2) {
		std::cout << "It's a prime number!\n";
	}
	return 0;
}
