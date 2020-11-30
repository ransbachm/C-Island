// literal datatype example

#include <string>
#include <iostream>
using std::cout; using std::string;

struct Value {
    int value_ = -1;
    int P = -1;

    constexpr Value(int value) : value_{value} {}
    constexpr Value(const char str[]) {
        value_ = std::atoi(str); // unsafe, does not throw
        P = value_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Value val) {
        return os << val.value_;
    }
};

namespace customLit {
    constexpr Value operator"" _v(const char str[], size_t len) {return Value{str};}
    constexpr Value operator"" a(const char str[], size_t len) {return Value{str};} // DO NOT
}
int main() {
    // basic
    constexpr Value val{2};

    int arr [val.value_];
    cout << "Length : " << sizeof(arr) / sizeof(arr[0]) << "\n";

    // custom literals
    using namespace customLit;
    cout << "39"_v << " " << "Hello"_v << "\n";
    Value l = "11"_v;

    cout << std::is_literal_type<Value>::value << "\n";

    // do not, just a demo
    int arr2 ["Gig"a.P];
    cout << sizeof(arr2) / sizeof(arr2[0]) << "\n";


}