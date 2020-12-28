#include <iostream>
#include <functional>

using std::cout;


int calc(int a, int b, std::function<int(int, int)> op) {
    return op(a,b);
}

int plus(int a, int b) {return a+b;}
int mult(int a, int b) {return a*b;}

int main() {
    cout << calc(3,5, plus) << "\n";
    cout << calc(3,5, mult) << "\n";
}