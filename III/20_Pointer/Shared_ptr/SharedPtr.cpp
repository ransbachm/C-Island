// page 498
#include <memory> // shared_ptr
#include <iostream> // cout
#include <vector>
#include <random> // uniform_int_distribiution, random_device

namespace {
using std::shared_ptr; using std::make_shared;
using std::vector; using std::cout;

struct Astroid {
    int points_ = 100;
    int structure_ = 10;
};

struct Ship {
    shared_ptr<Astroid> lastFiredOn_{}; // is shared with the astroids_ vector in GameBoard
    int score_ = 0;
    int firepower_ = 1;
    bool fireUpon(shared_ptr<Astroid> a);
};

struct GameBoard {
    vector<shared_ptr<Astroid>> astroids_;
    explicit GameBoard(int nAstroids);
    bool shipFires(Ship& ship);
};
}

// implementation
bool Ship::fireUpon(shared_ptr<Astroid> a) {
    if(!a) return false; // invalid astroid
    a->structure_ -= firepower_;
    if(a.get() == lastFiredOn_.get()) 
        firepower_ *= 2;
    else
        firepower_ = 1;
    lastFiredOn_ = a;
    return a->structure_ <= 0; // return true if was destroyed 
}

GameBoard::GameBoard(int nAstroids) : astroids_{} {
    for(int i=0; i<nAstroids; ++i)
        astroids_.push_back(make_shared<Astroid>());
}

int diceThrow(int min, int max) {
    static std::random_device e;
    //static std::default_random_engine e;
    return std::uniform_int_distribution<int>{min, max}(e);
}

bool GameBoard::shipFires(Ship& ship) {
    int idx = diceThrow(0, astroids_.size()-1);
    bool destroyed = ship.fireUpon(astroids_[idx]);
    if(destroyed) {
        ship.score_ += astroids_[idx]->points_;
        astroids_.erase(astroids_.begin() + idx); // find pointer with position + begin
    }
    return astroids_.size() == 0;
}

void simulate_game() {
    GameBoard game{10};
    Ship ship{};
    for(int i=0; i<80; ++i) {
        if(game.shipFires(ship)) {
            cout << "Cleard in " << i+1 << " shots! ";
            break;
        }
    }
    cout << "You scored " << ship.score_ << " points!\n";
}

int main() {
    for(int i=0; i<2'000; ++i)
        simulate_game();
}