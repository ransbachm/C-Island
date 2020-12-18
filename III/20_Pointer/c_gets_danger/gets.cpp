// compile with g++ gets.cpp -std=c++11
#include <cstdio>
#include <iostream>

int main() {
    char str[5];
    gets(str); // cannot see array length -> does not care and can overwrite -> Dangerous
    std::cout << str;
}