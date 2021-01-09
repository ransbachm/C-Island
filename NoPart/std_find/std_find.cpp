
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector; using std::find; using std::cout;
using std::string; using std::ostream; using std::iterator;

class City {
    static int instances;

    const int id_;
    const string name_;
public:
    City(string name) : id_{++instances}, name_{name} {};
    friend bool operator==(const City& a, const City& b);
    friend ostream& operator<<(ostream& os, const City c);
};

int City::instances = 0;
bool operator==(const City& a, const City& b) {
    return a.name_ == b.name_;
};

ostream& operator<<(ostream& os, const City c) {
    return os << "City[id: " << c.id_ << ", name: " << c.name_ << "]";
};



int main() {
    City ber {"Berlin"}; City tky {"Tokyo"}; City nyc {"NewYork"};

    vector<City> cities {ber, tky, nyc};

    auto it = find(cities.begin(), cities.end(), City{"Tokyo"}); // CAUTION, RETURNS END ITERATOR (__LAST) IF IT DID NOT FIND ANYTHING | DO NOT DEREFERENCE

    cout << "Pos : " << it - cities.begin() << " Val : " << *it << "\n";

    auto it2 = find(cities.begin(), cities.end(), City{"Madrid"});
    cout << "Is end " << (it2 == cities.end()) << "\n";
}

 