#include <iostream>

using std::cout;

class CopyTester {
    static int instances;
    int val_;

    CopyTester(CopyTester&) = delete;
    CopyTester operator=(CopyTester&) = delete;

public:
    CopyTester() {
        val_ = instances++;
    }

    bool operator==(CopyTester& other) {
        return other.val_ == val_;
    }

    bool operator!=(CopyTester& other) {
        return !(other==*this);
    }
};
int CopyTester::instances = 0;


int main() {
    // shortcuts
    auto compare = [](int a, int b) -> int {return b-a;};
    auto compare2 = [](auto a,auto b) {return b-a;};

    cout << compare(20, 10) << "\n";
    cout << compare(10, 20) << "\n\n";

    // muteable via reference (not so great)
    int outerValue = -111;
    cout << outerValue << "\n";
    [&outerValue] {outerValue = 1;}(); // reference is used and outer variable is CHANGED
    cout << outerValue << "\n\n";

    // muteable COPY via mutable (bad style)
    int outerValue2 = 856;
    [outerValue2]() mutable {outerValue2 = 52; cout << outerValue2 << "\n";}();
    cout << outerValue2 << "\n\n";

    // CONST COPY for non reference
    CopyTester test {};
    CopyTester control{};
    cout << ((test != control && test == test) ? "Works" : "Broken") << "\n";
    // does not work because it would copy but the copy constructor is deleted
    //[test](CopyTester& testViaReference) {cout << (test == testViaReference);}(test);

    // does work but is reference so equal
    [&test](CopyTester& testViaReference) {cout << (test == testViaReference) << "\n\n";}(test);

    // = and &
    // = allows COPY access to all visible variables
    // & allows REFERENCE access to all visible variables
    // everthing else is an exception for that one variable

    int outerValue3 = 74;
    [=, &outerValue3]() {
        cout << outerValue << "\n";
        outerValue3 = 0;
    }();
    cout<<outerValue3 << "\n";

}