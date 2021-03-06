#include "Resistor.hpp"

using namespace std;

Resistor::Resistor(string name, double resistance, Connection& a, Connection& b) : Component(name, a, b), resistance{resistance} {}

double Resistor::get_current() const {
        //voltage / resistance
    double voltage{get_voltage()};
    //cout << "resistor current" << voltage/resistance <<endl;
    return voltage/resistance;
}

//resistor will move charge from most charged to least charged
void Resistor::set_connection_values(const double& timestep) {
    if(a.charge < b.charge){
        a.charge += (abs(a.charge - b.charge)/resistance) * timestep;
        b.charge -= (abs(a.charge - b.charge)/resistance) * timestep;
    }else{
        a.charge -= (abs(a.charge - b.charge)/resistance) * timestep;
        b.charge += (abs(a.charge - b.charge)/resistance) * timestep;
    }
    //cout << "setting connection values a and b" << endl;
}