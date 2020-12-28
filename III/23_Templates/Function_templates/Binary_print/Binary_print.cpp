#include <iostream>
#include <vector>
#include <set>
#include <bitset>

using std::cout; using std::vector; using std::ostream;
using std::set;

template<typename IT>
ostream& binPrint(ostream& os, IT begin, IT end) {
    for(IT it = begin; it != end; ++it) {
        std::bitset<4> bits (*it);
        os << bits << " ";
    }
    return os << "\n";
}

 
int main() {
    vector<int> vec {1,2,3,4};
    binPrint(cout, vec.cbegin(), vec.cend()); // std::begin would work too

    set<int> set = {5,6,7,8};
    binPrint(cout, begin(set), end(set));

    int arr[] = {9,10,11,12};
    binPrint(cout, std::begin(arr), std::end(arr));

}