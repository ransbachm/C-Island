#include <iostream>

/* using g++ 9.3.0 on Pop-Os 20.04 LTS 
this does compile to a program that returns random values (random RAM)
Aperrently this is otherwise in clang and gcc
This is perfectly okay according to the spec 
because the output is not defined >> undefined behaviour
*/

int return1 () {}

int main() {
    std::cout << return1(); 
}