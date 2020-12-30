#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using std::string; using std::cout; using std::set;
using std::begin; using std::end; using std::vector;

struct Color {
    string name_;
};

bool operator<(const Color& a, const Color& b) {
    return a.name_ < b.name_;
}

template<typename T>
void print(T toPrint) {
    for(const Color& element : toPrint)
        std::cout << element.name_ << " | ";
    std::cout << "\n";
}


struct SortByNameLength {
    bool operator()(const Color& a, const Color& b) {
        return a.name_.length() < b.name_.length();
    };
};

int main() {
    // use functor in set
    set<Color> colors {{"Red"}, {"Green"}, {"Blue"}, {"Some other long color"}, {"E"}};
    print(colors);
    set<Color, SortByNameLength> colorsByNameLength {begin(colors), end(colors)};
    print(colorsByNameLength);

    // use functor for sort
    cout << "\n";
    vector<Color> alsoSortable {{"Red"}, {"Green"}, {"Blue"}, {"Some other long color"}, {"E"}};
    sort(begin(alsoSortable), end(alsoSortable));
    print(alsoSortable);
    sort(begin(alsoSortable), end(alsoSortable), SortByNameLength{});
    print(alsoSortable);

    // use lambda for sort
    cout << "\n";
    vector<Color> useLambda {{"Red"}, {"Green"}, {"Blue"}, {"Some other long color"}, {"E"}};
    sort(begin(useLambda), end(useLambda));
    print(useLambda);
    sort(begin(useLambda), end(useLambda), 
        [](const Color& a, const Color& b) {return a.name_.length() < b.name_.length();});
    print(useLambda);


};