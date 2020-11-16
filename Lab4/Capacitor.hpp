#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    Capacitor(std::string name, float fahrad, Connection& a, Connection& b);
    void simulate() const override;
    void current() override;
    void set_connection_values(float timestep);
    float getcurrent() const override;

private:
    float fahrad{0.0};
    float charge{0.0};
};

#endif