#include "Component.hpp"

using namespace std;

Component::Component(std::string name, Connection& a, Connection& b) : name{name}, a{a}, b{b} {}

int Component::getvoltage(){
    cout << "Voltage: " << endl;
}

