#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>

struct Connection {
    //contain current charge of connection
    float charge{};
};

class Component {
public:
    Component(std::string name, Connection& a, Connection& b);
    virtual ~Component() = default;
    virtual void simulate() const = 0;
    virtual float get_current() = 0;
    float get_voltage();
protected:
    //every component has a and b and name
    Connection& a;
    Connection& b;
    std::string name{""};
};

#endif