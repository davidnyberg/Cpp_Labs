#ifndef BATTERY_H
#define BATTERY_H

#include "Component.hpp"

class Battery : public Component {
public:
    Battery(std::string name, double voltage, Connection& a, Connection& b);
    void simulate() const override;
    void set_connection_values(double& timestep) override;
    double get_current() const override;
    std::string get_name() const override;
private:
    double voltage{0.0};
};

#endif