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
    virtual void set_connection_values(float& timestep) = 0;
    virtual float get_current() const = 0;
    float get_voltage() const;
    virtual std::string get_name() const = 0;
protected:
    //every component has a and b and name
    Connection& a;
    Connection& b;
    std::string name{""};
};

#endif