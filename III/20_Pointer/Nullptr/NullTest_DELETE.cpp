#include <iostream>
using std::cout;

int main() {
    cout << "Hello, world!\n";
    int* crash = nullptr;
    cout << *crash;
    cout << "Done";
}