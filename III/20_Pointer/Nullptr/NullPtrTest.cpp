#include <iostream>
using std::cout;

void crash(bool actually) {
    if(!actually) {
        *((int*) nullptr); // some more undefined behaviour over here
    } else { // actually crash
        cout << *((int*) nullptr);
    }
}
int main() {
    
    crash(false);
    cout << "Survived\n";
    crash(true);
    cout << "Again";

}