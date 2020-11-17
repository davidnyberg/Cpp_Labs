#include "Resistor.hpp"

using namespace std;

Resistor::Resistor(string name, float resistance, Connection& a, Connection& b) : Component(name, a, b), resistance{resistance} {}

void Resistor::simulate() const {
    cout << "resistorar SIM" << endl;
}

float Resistor::get_current() {
        //voltage / resistance
    float voltage{get_voltage()};
    cout << "resistor current" << voltage/resistance <<endl;
    return voltage/resistance;
}

void Resistor::set_connection_values(float& timestep) {
    if(a.charge < b.charge){
        a.charge = (abs(a.charge - b.charge)/resistance) * timestep;
    }else{
        b.charge = (abs(a.charge - b.charge)/resistance) * timestep;
    }
    cout << "setting connection values a and b" << endl;
}