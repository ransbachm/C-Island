#include <iostream>

using std::ostream; using std::cout;

struct PrintMe {};

ostream& operator<<(ostream& os, const PrintMe& pm) {
    return os << "PrintMe was printed";
}

template<typename T>
void print(T toPrint) {
    cout << "[Template] \t" << toPrint << "\n";
}

void print(double toPrint) { // will be prefered to the template
    cout << "[Custom] \t" << toPrint << "\n";
}

template<typename T>
void betterPrint(const T& toPrint) {
    cout << toPrint << "\n";
}

int main() {
    // first use of a template instantiates it
    print<int>(1); // explicit
    print(-3); // implicit
    print(3.14); // overloaded double will be prefered to the template
    print<double>(3.14); // explicitly use template
    print("Templates are great");
    print<PrintMe>(PrintMe{}); // again expicit
    print(PrintMe{}); // again implicit
    betterPrint(PrintMe{});
}