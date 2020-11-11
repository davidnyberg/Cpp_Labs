#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.hpp"

class Capacitor : public Component {
public:
    void simulate() const override {
        std::cout << "capacitor simulate" << std::endl;
    }
private:
    double farad{};
    double load{};
};

#endif