#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.hpp"

class Resistor : public Component {
public:
    Resistor(std::string name, double resistance, Connection& a, Connection& b);
    void set_connection_values();
    void simulate() const override;
    void current() override;
    float getcurrent() const override;
private:
    double const resistance{0.0};
};

#endif