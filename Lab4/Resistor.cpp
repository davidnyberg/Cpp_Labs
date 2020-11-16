#include "Resistor.hpp"

using namespace std;

Resistor::Resistor(string name, double resistance, Connection& a, Connection& b) : Component(name, a, b), resistance{resistance} {}

void Resistor::simulate() const {
    cout << "resistorar SIM" << endl;
}

void Resistor::current() {
        //voltage / resistance
    cout << "resistor current" << endl;
}

void Resistor::set_connection_values() {
    cout << "setting connection values a and b" << endl;
    a.charge = {0.0};
    b.charge = {0.0};
}

float Resistor::getcurrent() const {
    cout << "get current" << endl;
}