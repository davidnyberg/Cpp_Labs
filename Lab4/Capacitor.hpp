#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    Capacitor(std::string name, double fahrad, Connection& a, Connection& b);
    void simulate() const override;
    void current() override;
    void set_connection_values();
    float getcurrent() const override;

private:
    double fahrad{0.0};
};

#endif