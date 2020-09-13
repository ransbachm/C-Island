
#ifndef DATE
#define DATE

#include <iostream>

class Date {
        Year year_;
        Month month_ {1}; // filled if for Date(int) constructor
        Day day_ {1};
public:
        explicit Date(int y) : year_{y} {}
        Date(Year y, Month m, Day d) : year_{y}, month_{m}, day_{d} {}
        ostream& print(ostream& os) const;
};

#endif
