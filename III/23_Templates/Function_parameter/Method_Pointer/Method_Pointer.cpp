#include <iostream>
#include <functional>
#include <memory>

using std::cout; using std::make_unique;

struct Class {
    double print(int i) {std::cout << i; return 3.14;};
};

int main() {
    double(Class::*method_pointer)(int) = &Class::print; // & is not optinal anymore
    std::function<double (Class*, int)> method_pointer2 = &Class::print; // same as above


    // not for some unreadable c style syntax
    auto obj = make_unique<Class>(); // im using a smart pointer, change my mind
    Class obj2{};
    cout << (obj.get()->*method_pointer)(0) << "\n"; // the c syntax is really BAD, use cpp / auto

    // better cpp syntax
    cout << method_pointer2(obj.get(), 0) << "\n";
}