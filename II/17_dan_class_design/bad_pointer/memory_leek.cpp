#ifndef __BI_VALUE_STORE__
#define __BI_VALUE_STORE__


#include <string>
#include "value.hpp"
#include <iostream>
#include <memory>

using std::string; using std::cout;

class bi_value_store {
    /*
    value* firstVal_; // raw pointer -> bad
    value* secondVal_;
    */

   std::unique_ptr<value> firstVal_;
   std::unique_ptr<value> secondVal_;

public:
    // new value works because of implicit type conversion in constructor of unique_ptr
    bi_value_store(string first, string second) : firstVal_{new value}, secondVal_{new value} {}

    const value* getFirst() const {
        return firstVal_.get();
    }


};

void leek() {
    // this would leek memory
    try {
        //cout << "Now creating s1\n";
        auto s1 = bi_value_store{"ABC", "DEF"};
        //cout << "Now creating s1\n";
        auto s2 = bi_value_store{"GHI", "JKL"};
        //cout << "Done creating s1 and s2!\n"; // should not be called
    } catch (std::runtime_error err) {
        //cout << "There was an error!\n";
    }
    //cout << "Done.\n";
}

int main() {
    while(true) leek();
}



#endif