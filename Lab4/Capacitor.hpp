#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    Capacitor(std::string name, double farad, double load, Connection& a, Connection& b);
    void simulate() const override;
    void current() override;

private:
    double farad{};
    double load{};
};

#endif