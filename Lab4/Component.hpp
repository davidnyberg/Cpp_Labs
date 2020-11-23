#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>

//TODO: get_name is identical in all Components. Therefore, it should
//not be defined by each class.
//DONE: Implemented get_name in component and now every subclass does not need to implement the same thing

struct Connection {
    //contain current charge of connection
    double charge{};
};

class Component {
public:
    Component(std::string name, Connection& a, Connection& b);
    virtual ~Component() = default;
    virtual void set_connection_values(const double& timestep) = 0;
    virtual double get_current() const = 0;
    double get_voltage() const;
    std::string get_name() const;
protected:
    //every component has a and b and name
    Connection& a;
    Connection& b;
    std::string name{""};
};

#endif
