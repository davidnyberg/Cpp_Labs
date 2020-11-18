#include "Resistor.hpp"

using namespace std;

Resistor::Resistor(string name, float resistance, Connection& a, Connection& b) : Component(name, a, b), resistance{resistance} {}

void Resistor::simulate() const {
    cout << "resistorar SIM" << endl;
}

string Resistor::get_name() const {
    return name;
}

float Resistor::get_current() const {
        //voltage / resistance
    float voltage{get_voltage()};
    //cout << "resistor current" << voltage/resistance <<endl;
    return voltage/resistance;
}

//resistor will move charge from most charged to least charged
void Resistor::set_connection_values(float& timestep) {
    //a is 5, b is 9
    if(a.charge < b.charge){
        a.charge += (abs(a.charge - b.charge)/resistance) * timestep;
        b.charge -= (abs(a.charge - b.charge)/resistance) * timestep;
    }else{
        a.charge -= (abs(a.charge - b.charge)/resistance) * timestep;
        b.charge += (abs(a.charge - b.charge)/resistance) * timestep;
    }
    //cout << "setting connection values a and b" << endl;
}