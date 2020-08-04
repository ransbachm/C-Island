

#include <iostream> // cout, cerr
#include <vector>
#include <string>
#include <fstream> // ifstream
#include <stdexcept> // invalid_argument

using std::vector; using std::string; using std::cout; using std::ifstream;

size_t countWords(const string& filename) { // size_t -> unsigned int -> greater than 0
	std::ifstream file{}; // create unopened

	// register for exceptions
	file.exceptions(ifstream::failbit | ifstream::badbit);
	file.open(filename);

	size_t count = 0;
	string word;
	file.exceptions(ifstream::badbit);
	while(!file.eof()) {
		file >> word;
		count++;
	}
	return count-1; // on eof a word was stil read
}


void process(const vector<string>& args) {
	if(args.size() == 0) {
		throw std::invalid_argument{"Arg is missing"}
