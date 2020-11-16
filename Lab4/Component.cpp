#include "Component.hpp"

using namespace std;

Component::Component(std::string name, Connection& a, Connection& b) : name{name}, a{a}, b{b} {}

float Component::getvoltage(){
    cout << "Voltage: " << a.charge - b.charge << endl;
    return a.charge - b.charge;
}

