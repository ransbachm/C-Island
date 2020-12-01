#include <iostream> // cout
#include <vector> // vector
using std::cout; using std::vector; using std::ostream;

ostream& printVector(ostream& os, vector<int>& arg) {
    for(int crr : arg) {
        os << crr << " ";
    }
    return os;
}

int main() {
    vector<int> values{};
    // comment out to work properly
    // vector moves its elements when getting bigger and relocating elements
    values.reserve(50); 

    // dangerous part
    int* max = nullptr; // raw pointer (as user)
    for(int crr : {1,2,13,20,30,500,1024, -39, 0, 4, -9999}) {
        values.push_back(crr);
        if(!max || *max < crr) { // if max nullptr (not ye assigned) or current value bigger 
            max = &values.back(); // referenc the the latest added element (copy of crr)
        }
    }
    // actually wanted code
    printVector(cout, values) << "\n";
    cout << *max << "\n";
    *max = -0101010101;
    printVector(cout, values) << "\n";
}