#ifndef __COMPUTER__
#define COMPUTER

#include <iostream>
#include <string>

using std::string;

class computer {
    int id_;
    string type_;
public:
    virtual string getName() const = 0;
    virtual bool isOn() const = 0;
};

#endif