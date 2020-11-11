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