#include <iostream>
#include "base_impl.hpp"

using std::cout;
using chronos2::date; using chronos2::day;
using chronos2::year;

int main() {

    day d {12};
    date date {2020};
    year y {3939};
    

    d.print(cout);
    cout << "\n";
    date.print(cout) << "\n";
    cout << date << "\n";
    cout << "Last day : " << y.getLastDay() << "\n";
    cout << y.getName() << " | " << d.getName() << "\n";

}