#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.hpp"

class Resistor : public Component {
public:
    Resistor(std::string name, double resistance, Connection& a, Connection& b);
    void set_connection_values(double& timestep) override;
    void simulate() const override;
    double get_current() const override;
    std::string get_name() const override;

private:
    double const resistance{0.0};
};

#endif