#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.hpp"

class Resistor : public Component {
public:
    Resistor(std::string name, double resistance, Connection& a, Connection& b);// : Component(name, a, b), resistance{resistance} {}
    void simulate() const override {
        std::cout << "resistor simulate" << std::endl;
    }
    void current() override {
        std::cout << "current resisitor" << std::endl;
    }
private:
    double resistance{};
};

#endif