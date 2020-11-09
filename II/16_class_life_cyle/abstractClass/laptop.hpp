#ifndef __LAPTOP__
#define __LAPTOP__

#include <string>
#include "computer.hpp"

using std::string;
class laptop : public computer {
    string name_;
    string monitor_; // string because example
public:
    string getName() const override {
        return name_;
    }

    bool isOn() const override {
        return true; // test
    }

    string getMonitor() const {
        return monitor_;
    }
    

};
#endif