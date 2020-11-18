#include "Component.hpp"

using namespace std;

Component::Component(std::string name, Connection& a, Connection& b) : name{name}, a{a}, b{b} {}

float Component::get_voltage() const {
    //cout << "Voltage: " << abs(a.charge - b.charge) << endl;
    return abs(a.charge - b.charge);
}

