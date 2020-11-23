#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    Capacitor(std::string name, double fahrad, Connection& a, Connection& b);
    void set_connection_values(const double& timestep) override;
    double get_current() const override;
private:
    double fahrad{0.0};
    double charge{0.0};
};

#endif