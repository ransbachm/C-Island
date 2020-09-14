#include <iostream>
#include "base_impl.hpp"

int main() {
    using namespace chronos2;
    using std::cout;

    day d {12};
    date date {2020};

    cout << d << "\n";
    date.print(cout) << "\n";
    //cout << date;

}