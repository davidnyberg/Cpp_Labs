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
    virtual void set_connection_values(double& timestep) = 0;
    virtual double get_current() const = 0;
    double get_voltage() const;
    virtual std::string get_name() const = 0;
protected:
    //every component has a and b and name
    Connection& a;
    Connection& b;
    std::string name{""};
};

#endif