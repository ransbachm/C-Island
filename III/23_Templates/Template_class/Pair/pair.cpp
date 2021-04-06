#include <iostream>


// This class represents a generic container for two indipendent types
// >> a pair <<

template<typename T, typename E=T> // shortcut
class Pair {
    T first_;
    E second_;


    // this is made private to enforce the use of a friend function
    // (for demonstrative purpose)
    std::ostream& print(std::ostream& os) const {
        return os << "Pair{" << first_ << " | " << second_ << "}";
    }

public:
    Pair(T first, E second) : first_{first}, second_{second} {}

    T getFirst() {
        return first_;
    }

    E getSecond() {
        return second_;
    }

    // declate friend operator<< with the neccesary template
    template<typename T_, typename E_>
    friend std::ostream& operator<<(std::ostream& os, const Pair<T_, E_>& p);
};

// implement said friend operator
template<typename T, typename E>
std::ostream& operator<<(std::ostream& os, const Pair<T, E>& p) {
    return p.print(os);
}

int main() {
    // 'using XXX = XXX'  is made use of as a test
    using delcareDifferent = Pair<int, std::string>; // use different types
    using declareBoth = Pair<int, int>; // explicitly use the same type twice
    using declareOne = Pair<int>; // use the shortcut and only declares one type explicitly

    delcareDifferent dD {3, "We All B   ecome"};
    declareBoth dB {5,9};
    declareOne dO {13, 89};

    // print everything
    std::cout << dD << "\n\n" << dB << "\n\n" << dO << "\n";
}