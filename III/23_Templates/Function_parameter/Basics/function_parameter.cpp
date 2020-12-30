#include <iostream>
#include <functional>

using std::cout;


int calc(int a, int b, std::function<int(int, int)> op) {
    return op(a,b);
}

// c style syntax, implicitly converted to above
int calc_c(int a, int b, int(*op)(int, int)) {
    return op(a, b);
}

int plus(int a, int b) {return a+b;}
int mult(int a, int b) {return a*b;}

int main() {
    cout << calc(3,5, plus) << "\n";
    cout << calc(3,5, mult) << "\n";

    cout << calc_c(3,5, &plus) << "\n"; // not needed because converted to c++ style anyway
    cout << calc_c(3,5, &mult) << "\n";

    cout << calc_c(3,5, plus) << "\n";
    cout << calc_c(3,5, mult) << "\n";

}