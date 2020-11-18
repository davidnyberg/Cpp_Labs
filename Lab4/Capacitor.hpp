#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    Capacitor(std::string name, float fahrad, Connection& a, Connection& b);
    void simulate() const override;
    void set_connection_values(float& timestep);
    float get_current() const override;
    std::string get_name() const override;

private:
    float fahrad{0.0};
    float charge{0.0};
};

#endif