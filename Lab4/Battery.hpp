#ifndef BATTERY_H
#define BATTERY_H

#include "Component.hpp"

class Battery : public Component {
public:
    Battery(std::string name, double voltage, Connection& a, Connection& b);
    void set_connection_values(const double& timestep) override;
    double get_current() const override;
private:
    double voltage{0.0};
};

#endif