#include <iostream>
#include "../myValue.hpp"

void function(MyValue val) { // call by value
    std::cout << "(function)\n";
    MyValue localValue {"localValue"};
}

int main() {
    MyValue myV1 {"myV1"};
    function(MyValue{"temp"});
    function(myV1);
    {
        MyValue myV2 {"myV2"};
    }
}