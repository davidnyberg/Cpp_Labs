#include "Battery.hpp"

using namespace std;
Battery::Battery(std::string name, float voltage, Connection& a, Connection& b) : Component(name, a , b), voltage{voltage} {}

void Battery::simulate() const {
    cout << "battery simulation" << endl;
}

void Battery::current() {
    cout << "Battery has zero current" << endl;
}

void Battery::set_connection_values() const {
    cout << "setting connection values a and b" << endl;
    a.charge = {voltage};
    b.charge = {0.0};
}

float Battery::getcurrent() const {
    cout << "get current" << endl;
    return 0.0;
}