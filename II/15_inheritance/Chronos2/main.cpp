#include <iostream>
#include "base_impl.hpp"

int main() {
    using std::cout;
    using namespace chronos2;

    day d {12};
    date date {2020};

    d.print(cout);
    cout << "\n";
    date.print(cout) << "\n";
    cout << date;

}