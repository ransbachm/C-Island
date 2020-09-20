#include <iostream>
#include <iomanip>

using std::string; using std::cout; using std::setw;


struct MyValue {
    static int counter;
    int number_;
    string name_;

    explicit MyValue(string name) 
        : number_{++counter}, name_{name}
        {cout << setw(number_) << ' ' << "Constructor " << name_ << "\n";}
    
    MyValue(const MyValue &orig) 
        : number_{++counter}, name_{orig.name_} {}
    
    ~MyValue() {
        cout << setw(number_) << ' ' << "Destructor " << name_ << "\n";
    }
};

int MyValue::counter = 0;