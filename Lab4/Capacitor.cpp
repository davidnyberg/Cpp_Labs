#include "Capacitor.hpp"

using namespace std;

Capacitor::Capacitor(std::string name, double farad, double load, Connection& a, Connection& b) : Component(name, a, b), farad{farad}, load{load} {}


void Capacitor::simulate() const {
    cout << "in capacitor simulate" << endl;
}

void Capacitor::current() {
    cout << "capactior current" << endl;
}