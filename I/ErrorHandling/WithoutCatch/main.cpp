

#include <iostream> // cout, cerr
#include <fstream> 
#include <vector>
#include <string>

using std::vector; using std::string; using std::cout; using std::cerr;

int countWords(const string& filename) {
	std::ifstream file {filename};
	if(!file) {
		cerr << "Error opening the file\n";
		return -1;
	}

	int count = 0;
	string word;
	while(!file.eof()) {
		file >> word;
		++count;
	}
	return count -1; // because prefix increment, (probably)
}

bool process(const vector<string>& args) { // return true if everything is ok
	if(args.size() == 0) { // expect parameters
		cerr << "Argument(s) missing\n";
		return false;
	} else {
		bool result = true; // for final result
		for(const string filename : args) {
			cout << filename << ": ";
			int count = countWords(filename);
			if(count < 0) {
				cout << "Error!\n";
				result = false;
			} else {
				cout << count << "\n";
			}
		}
	return result;
	}
}



int main(int argc, const char* argv[]) {

	bool result = process({argv+1, argv+argc});

	if(result) {
		return 0;
	} else {
		cerr << "An error occured\n";
		return 1;
	}
}
