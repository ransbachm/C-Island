#include <iostream>

namespace {
    int echo(int in) {
        return in;
    }
}

int main() {
    std::cout << echo(1) << "\n";
}