#include <iostream>

template <typename T=int, size_t n=5> // shortcut
class MyArray {
    T elements_ [n] {0}; // internal data store >> array <<
public:
    // getter for size
    static constexpr size_t size() {return n;}
    // 'array' assignement operator
    T& operator[] (size_t index) {return elements_[index];}

    // operator<< for printing
    template<typename T1, size_t n1>
    friend std::ostream& operator<<(std::ostream& os, const MyArray<T1, n1> ma);
};

// operator<< for printing
template<typename T, size_t n>
std::ostream& operator<<(std::ostream& os, const MyArray<T,n> ma) {
    for(auto it : ma.elements_)
        os << it << " ";
    return os;
}

int main() {
    MyArray<int, 3> explicitBothTimes {}; // use explicit only 
    MyArray<int> implicitLength {}; // use implicit length
    MyArray<> allImplicit{}; // use all default

    // change content a bit
    for(size_t i=0; i<allImplicit.size(); ++i) {
        allImplicit[i] = i*3;
    }

    // output to screen
    std::cout << allImplicit << "\n";
}