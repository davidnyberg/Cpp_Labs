#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>

struct Connection {
    //contain current charge of connection
    double charge{};
};

class Component {
public:
    Component(std::string name, Connection& a, Connection& b);
    virtual ~Component() = default;
    virtual void simulate() const = 0;
    virtual void current() = 0;
    get voltage
    virtual getcurrent
protected:
    //every component has a and b and name
    Connection& a;
    Connection& b;
    std::string name{""};
};

#endif