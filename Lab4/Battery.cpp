#include "Battery.hpp"

using namespace std;
Battery::Battery(std::string name, double voltage, Connection& a, Connection& b) : Component(name, a , b), voltage{voltage} {}


void Battery::set_connection_values(const double& timestep) {
    //cout << "setting connection values a and b" << endl;
    a.charge = {voltage};
    b.charge = {0.0};
}

double Battery::get_current() const {
    //battery is always zero current
    //cout << "get battery current" << endl;
    return 0.0;
}