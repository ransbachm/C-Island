// 23.2.2, page 550
#include <iostream>
#include <limits>


template<typename INT_TYPE>
void infos(const char* name) {
    using L = typename std::numeric_limits<INT_TYPE>;
    std::cout
        << name
        << ", bits : " << L::digits
        << ", signed " << L::is_signed
        << ", min " << (long long) L::min()
        << ", max " << (long long) L::max()
        << "\n";
}

int main() {
    infos<char>("char");
    infos<short>("short");
    infos<unsigned short>("unsigned short");
    infos<int>("int");
    infos<unsigned>("unsigned");
    infos<long long>("long long");
}