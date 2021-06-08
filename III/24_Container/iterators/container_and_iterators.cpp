#include <iostream>
#include <vector>
#include <list>

using std::cout; using std::vector; using std::string;

// used for printing a vector<T>
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    // just a simple for loop would have probably been better here
    for(auto it = std::begin(vec); it != std::end(vec); ++it) {
        cout << *it;

        if(std::end(vec) -it != 1) { // if not last element
            cout << ", ";
        }
    }
    return os << "]\n";
}

// used for printing a list<T>
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& list) {
    string buf = "[";

    for(auto& elem : list) {
        buf += elem + ", ";
    }
    buf = buf.substr(0, buf.size()-2);
    buf += "]";

    return os << buf;
}

int main() {

    vector<int> a; // default constructor
    vector<int> b {}; // default constructor
    vector<int> c = {}; // also default constructor

    cout << a.size() << "\n";
    cout << a.size() << "\n";
    cout << a.size() << "\n";

    vector<int> inp (5,3); // using constructor -> 5x"3"
    vector<int> inp2 (3,5); // using constructor -> 3x"5"

    cout << inp << "\n";

    vector<int> d {1,2,3}; // using initializer list
    vector<int> out(d); // copy of d
    vector <int> out2(d); // also copy of d

    vector<int> out3 (std::move(d)); // actually moves the vector
    vector<int> out4 = std::move(out3); // moves, does not copy

    cout << out4 << "\n";
    cout << d << "\n"; // print after move -> data is gone
    
    std::list<string> source {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    auto from = source.begin();
    std::advance(from, 3); // does advance 3 but is slow on list
    auto to = from;
    std::advance(to, 3);

    vector<string> target (from, to); // does copy
    cout << "Data is still there\n" << source << "\n";
    // this will move, not copy
    vector<string> moveTarget (std::make_move_iterator(from), std::make_move_iterator(to));
    cout << "Data is gone\n" << source << "\n";
}