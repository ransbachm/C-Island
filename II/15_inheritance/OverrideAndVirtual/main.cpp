#include <iostream>

class Base_1 {
    int magic_ = 3939;
    int getValue() const {return magic_;}
public:
    std::ostream& print(std::ostream& os) const {return os << getValue();}
};

class Base_2 {
    int magic2_ = 82105110; // has meaning, gotta dig deeper
    virtual int getValue() const {return magic2_;}
public:
    std::ostream& print(std::ostream& os) const {return os << getValue();}
};  

class Impl_1 : public Base_1 {
    int impl_magic1 = 77105107117;

    int getValue() const {return impl_magic1;} // does only "half override", see ~page 370
};

class Impl_2 : public Base_2 {
    int impl_magic2 = 76101110;

    // realy overrides the method, 
    // the 'override' keyword is optional but strongly encouraged
    virtual int getValue() const override {return impl_magic2;} 


};

int main() {
    Impl_1 i1 {};
    Impl_2 i2 {};

    i1.print(std::cout); std::cout << "\n";
    i2.print(std::cout); std::cout << "\n";

}