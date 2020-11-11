#include "Battery.hpp"

using namespace std;
Battery::Battery(std::string name, double voltage, Connection& a, Connection& b) : Component(name, a , b), voltage{voltage} {}

void Battery::simulate() const {
    cout << "battery simulation" << endl;
}

void Battery::current() {
    cout << "Battery has zero current" << endl;
}

void Battery::print_voltage() const {
    cout << "Voltage: " << voltage << endl;
}

void Battery::set_connection_values() const {
    cout << "setting connection values a and b" << endl;
    a.charge = {voltage};
    b.charge = {0.0};
}