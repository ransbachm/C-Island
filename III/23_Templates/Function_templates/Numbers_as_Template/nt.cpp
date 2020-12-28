#include <iostream>
#include <array>

using std::cout; using std::ostream;

template<size_t SIZE>
std::array<int, SIZE> createArray() {
    return std::array<int, SIZE>{};
}

using std::array; // not stated earlier to reduce confusion

int main() {
    auto arr = createArray<4>();
    arr[2] = 33;


    for(auto crr : arr)
        cout << crr << " ";

}