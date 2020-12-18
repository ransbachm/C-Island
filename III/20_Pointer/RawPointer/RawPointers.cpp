#include <iostream>
#include <vector>
#include <numeric>
using std::vector; using std::cout;

bool isPrim(const int& toTest, const vector<int*> prims) {
    for(int* crr : prims) {
        if((*crr) * (*crr) > toTest) return true; // too big
        if(toTest % *crr == 0) return false; // does divide
    }
    return true;
}

vector<int*> getPrims(int until) {
    vector<int> allNumbers {until-2};
    std::iota(allNumbers.begin(), allNumbers.end(), 3); // 3..until
    vector<int*> prims{}; // references ints in allNumbers!
    int two = 2;
    prims.push_back(&two);

    for(int &crr : allNumbers)
        if(isPrim(crr, prims))
            prims.push_back(&crr); // &z -> address of z

    cout << prims.size() << "    ";
    for(int prim : allNumbers)
        cout << prim << ",";
    return prims; // DO NOT
}

int main() {
    vector<int*> prims = getPrims(100);
    for(int* prim : prims)
        cout << *prim << ",";
    
}