#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

 // throwing an exception in noexcept calls terminate() and terminates the process
int main() noexcept {
    cout << "begin\n";
    throw "boom";  // generates compiler warning tho (g++ 10.2.0)
    //terminate(); // similar to above, is internally called by the exception handling
    cout << "something is broken\n";
}
