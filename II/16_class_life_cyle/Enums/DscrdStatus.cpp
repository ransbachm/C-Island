
// imaginary status for an app

#include <string>
#include <iostream>
using std::string; using std::cout;

enum Status {
    ONLINE, AFK, BUSY, OFFLINE, INVISIBLE,
};

class User {
    static int instances;
public:
    const string name_;
    const int id_;
    Status status_;
    static int countInstances() {return instances;}

    User(string name, Status status) : name_{name}, status_{status}, id_{instances++} {}

};
int User::instances = 0;

int main() {
    User pgn {"PGN", Status::ONLINE};
    User ptx = {"PTX", Status::AFK};
    pgn.status_ = Status::INVISIBLE;

    switch(pgn.status_) { // just an example, there are better ways to do this
        case ONLINE: cout << "User is online"; break;
        case AFK: cout << "User is afk"; break;
        case BUSY: cout << "User is busy"; break;
        case OFFLINE: // fall through
        case INVISIBLE: cout << "User is offline"; break;
    }
    cout << "\nThere are " << User::countInstances() << " users\n";

}