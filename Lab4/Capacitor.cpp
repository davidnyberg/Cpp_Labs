#include "Capacitor.hpp"

using namespace std;

Capacitor::Capacitor(std::string name, float fahrad, Connection& a, Connection& b) : Component(name, a, b), fahrad{fahrad} {}


void Capacitor::simulate() const {
    cout << "battery simulation" << endl;
}

void Capacitor::current() {
    cout << "Battery has zero current" << endl;
}

void Capacitor::set_connection_values(float timestep) {
    cout << "setting connection values a and b" << endl;

    float potential{abs(a.charge - b.charge)};
    if (potential - charge < 0) {
        charge = {0.0};
    } else {
        charge = fahrad * (potential - charge) * timestep;
    }
}

float Capacitor::getcurrent() const {
    cout << "get current" << endl;
    return 0.0;
}
