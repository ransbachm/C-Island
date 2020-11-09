#ifndef __COMPUTER__
#define COMPUTER

#include <iostream>
#include <string>

using std::string;

class computer {
    int id_;
    string type_;
public:
    virtual string getName() const;
    virtual bool isOn() const;
};

#endif