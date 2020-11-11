#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>

//struct because aggregate
struct Connection {
    //contain current charge of connection
    double charge{};
};

class Component {
public:
    Component(std::string name, Connection& a, Connection& b);
    virtual void simulate() const = 0;
    virtual void current() = 0;
    virtual ~Component() = default;
protected:
    //allias every component has a and b
    Connection& a;
    Connection& b;
    std::string name{""};
};

#endif