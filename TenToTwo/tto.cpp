




#include <iostream>

void printBin(int x) {
	while(x>0) {
		int a = x/2;
		int b = x%2;
		std::cout << x << " / 2 = " << a << ", Rest " << b << "\n";
		x = a;
	}
	std::cout << std::endl;
}


int main(int argc, char* argv []) {
	printBin(strtol(argv[1], NULL, 10));

}


