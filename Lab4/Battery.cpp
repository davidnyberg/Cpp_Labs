#include "Battery.hpp"

using namespace std;
Battery::Battery(std::string name, double voltage, Connection& a, Connection& b) : Component(name, a , b), voltage{voltage} {}

<<<<<<< HEAD
=======
string Battery::get_name() const {
    return name;
}
>>>>>>> 077dcee4a4fdd6224ae6fe1a9022cba731b92b42

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