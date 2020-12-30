#include <iostream>

struct HW {
    int operator()(int i) {std::cout << "hello world\n"; return i;};
};

void test(HW hello_world) {
    hello_world(0);
}

int main() {
    test(HW{});
    std::cout << HW{}(39) << "\n";
}