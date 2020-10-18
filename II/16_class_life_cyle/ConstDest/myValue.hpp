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
    
    // REMEMBER: When defining a custom copy constuctor / copy constructor / assign operator ..
    // all of them should most likely be defined.
    MyValue(const MyValue &orig) 
        : number_{++counter}, name_{orig.name_} {}
    
    ~MyValue() {
        cout << setw(number_) << ' ' << "Destructor " << name_ << "\n";
    }

    MyValue& operator=(const MyValue& rightSide) {

        // 1. Test self assignement
        if(this != &rightSide) {

            // 2. free allocated resources, here none

            // 3. transfer members
            name_ = rightSide.name_ + "-Assigned (" + name_ + " before)";
            // number_ stays the same for same intendation
        }
        // return itself
        return *this;
    }
};

int MyValue::counter = 0;