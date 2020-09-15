#ifndef BASE
#define BASE

#include <iostream>

class base {
protected:
    int value_;
    base(int v) : value_{v} {}
public:
    std::ostream& print(std::ostream& os) const;

    // sadly you can't just override member variables
    // inline
    std::string getName() const {return "base";}
};

std::ostream& operator<<(std::ostream& os, base base); 

#endif
