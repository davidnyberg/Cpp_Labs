#include "Resistor.hpp"

using namespace std;

Resistor::Resistor(string name, double resistance, Connection& a, Connection& b) : Component(name, a, b), resistance{resistance} {}

void Resistor::simulate() const {
    cout << "resistorar SIM" << endl;
}

void Resistor::current() {
        //voltage / resistance
    float voltage{getvoltage()};
    cout << "resistor current" << voltage/resistance <<endl;
}

void Resistor::set_connection_values(float timestep) {
    if(a.charge < b.charge){
        a.charge = (abs(a.charge - b.charge)/resistance) * timestep;
    }else{
        b.charge = (abs(a.charge - b.charge)/resistance) * timestep;
    }
    cout << "setting connection values a and b" << endl;
}

float Resistor::getcurrent() const {
    cout << "get current" << endl;
    return 0.0;
}