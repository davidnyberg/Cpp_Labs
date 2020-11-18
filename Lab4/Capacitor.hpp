#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    Capacitor(std::string name, double fahrad, Connection& a, Connection& b);
    void simulate() const override;
    void set_connection_values(double& timestep) override;
    double get_current() const override;
    std::string get_name() const override;

private:
    double fahrad{0.0};
    double charge{0.0};
};

#endif