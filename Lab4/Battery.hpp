#ifndef BATTERY_H
#define BATTERY_H

#include "Component.hpp"

class Battery : public Component {
public:
    Battery(std::string name, double voltage, Connection& a, Connection& b);// : Component(name, a , b), voltage{voltage} {}

    void simulate() const override;
    void current() override;

private:
    //voltage over a component is measured by taking the difference between each terminal.
    double voltage{};
};

#endif