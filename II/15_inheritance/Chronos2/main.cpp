#include <iostream>
#include "base_impl.hpp"

using std::cout;

int main() {

    chronos2::day d {12};
    chronos2::date date {2020};


    d.print(cout);
    cout << "\n";
    date.print(cout) << "\n";
    cout << date << "\n";

}