#include "Capacitor.hpp"

using namespace std;

Capacitor::Capacitor(std::string name, double fahrad, Connection& a, Connection& b) : Component(name, a, b), fahrad{fahrad} {}

string Capacitor::get_name() const {
    return name;
}

void Capacitor::simulate() const {
    cout << "battery simulation" << endl;
}

void Capacitor::set_connection_values(double& timestep) {
    //cout << "setting connection values a and b" << endl;
    //will drain its most positive terminal of some positive charge, 
    //and drain its least positive terminal of an equal amount of negative charge

    double potential{get_voltage()};

    if (potential - charge < 0) {
        charge = {0.0};
    } else {
        cout << charge << endl;
        charge += fahrad * (potential - charge) * timestep;
    }
    cout << charge << endl;
    
    b.charge -= charge;
    a.charge -= charge;
}

double Capacitor::get_current() const {
    //current through a capacitor is approximated by C(V − L)
    //cout << "get Capacitor current" << endl;
    return fahrad * (get_voltage() - charge);
}
