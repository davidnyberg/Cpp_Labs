#ifndef BATTERY_H
#define BATTERY_H

#include "Component.hpp"

class Battery : public Component {
public:
    Battery(std::string name, double voltage, Connection& a, Connection& b);
    void simulate() const override;
    void current() override;
    void print_voltage() const;
    void set_connection_values() const;
private:
    //voltage over a component is measured by taking the difference between each terminal.
    double const voltage{};
};

#endif