

#include <string>
#include <iostream>


int main(int argc, char* argv[]) {
	using namespace std;

	if(argc < 2) {
		cout << "Please specify the ammount of characters that sould be printed.\n";
		return 1;
	}

	string s = "abc";
	int length = (int) strtol(argv[1], NULL, 10);

	for(int i=0; i<length; i++) {
		cout << s.at(i);
	}

	for(int i=0; i<length; i++) {
		cout << s[i];
	}
}
