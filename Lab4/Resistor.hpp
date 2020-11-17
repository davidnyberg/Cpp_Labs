#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.hpp"

class Resistor : public Component {
public:
    Resistor(std::string name, float resistance, Connection& a, Connection& b);
    void set_connection_values(float& timestep);
    void simulate() const override;
    float get_current() override;
private:
    float const resistance{0.0};
};

#endif