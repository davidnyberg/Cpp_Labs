#include "Capacitor.hpp"

using namespace std;

Capacitor::Capacitor(std::string name, double fahrad, Connection& a, Connection& b) : Component(name, a, b), fahrad{fahrad} {}


void Capacitor::simulate() const {
    cout << "battery simulation" << endl;
}

void Capacitor::current() {
    cout << "Battery has zero current" << endl;
}

void Capacitor::set_connection_values() {
    cout << "setting connection values a and b" << endl;
    a.charge = {0.0};
    b.charge = {0.0};
}

float Capacitor::getcurrent() const {
    cout << "get current" << endl;
    return 0.0;
}
