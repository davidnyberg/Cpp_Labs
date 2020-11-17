#ifndef BATTERY_H
#define BATTERY_H

#include "Component.hpp"

class Battery : public Component {
public:
    Battery(std::string name, float voltage, Connection& a, Connection& b);
    void simulate() const override;
    void set_connection_values() const;
    float get_current() override ;
private:
    float voltage{0.0};
};

#endif