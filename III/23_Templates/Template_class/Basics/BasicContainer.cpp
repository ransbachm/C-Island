#include <iostream>

using namespace std;

template<typename T>
class BasicContainer {
    T data_;
public:

    // prefer constref over values when using templates (also when not using them)
    // CONSTREF so the data cannot be changed from the outside
    void setData(const T& d);
    T getData() const {return data_;}

    // for non inline definition
    ostream& printData(ostream& os) const;
};

template <typename T>
ostream& BasicContainer<T>::printData(ostream& os) const {
    return os << data_;
}

template<typename T>
void BasicContainer<T>::setData(const T& d) {
    data_ = d;
}

template<>
void BasicContainer<std::string>::setData(const std::string& d) {
    data_ = "[" + d + "]";
}

int main() {

    BasicContainer<int> c {};
    c.setData(23);
    cout << c.getData() << "\n";
    c.printData(cout) << "\n";

    BasicContainer<string> c2 {};
    c2.setData("Orange");
    cout << c2.getData() << "\n";
    c2.printData(std::cout) << "\n";
    
}