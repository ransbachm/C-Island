#ifndef BASE
#define BASE

#include <iostream>

class base {
protected:
    int value_;
    base(int v) : value_{v} {}
public:
    std::ostream& print(std::ostream& os) const;
};

#endif