
#include <string>
#include <iostream>

using std::string; using std::cout;


struct Person {
	string name_;
	int alter_;
	string ort_;
	void drucke(); // mark in struct 'declare'
};

// implement, instance variables are accessable
void Person::drucke() {
	cout << name_ << 
		" (" << alter_ << ") aus " << ort_ << "\n";
}

int main() {
	Person otto {"Otto", 45, "Kassel"};
	otto.drucke();
}
