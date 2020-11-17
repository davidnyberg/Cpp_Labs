#include "Capacitor.hpp"

using namespace std;

Capacitor::Capacitor(std::string name, float fahrad, Connection& a, Connection& b) : Component(name, a, b), fahrad{fahrad} {}


void Capacitor::simulate() const {
    cout << "battery simulation" << endl;
}

void Capacitor::set_connection_values(float& timestep) {
    cout << "setting connection values a and b" << endl;

    float potential{get_voltage()};

    if (potential - charge < 0) {
        charge = {0.0};
    } else {
        charge = fahrad * (potential - charge) * timestep;
    }
    a.charge = {charge};
    b.charge = {charge};
}

float Capacitor::get_current() {
    //current through a capacitor is approximated by C(V − L)
    cout << "get Capacitor current" << endl;
    return fahrad * (get_voltage() - charge);
}
