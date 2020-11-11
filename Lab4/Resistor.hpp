#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.hpp"

class Resistor : public Component {
public:
    Resistor(std::string name, double resistance, Connection& a, Connection& b);
    void simulate() const override;
    void current() override;
private:
    double const resistance{};
};

#endif