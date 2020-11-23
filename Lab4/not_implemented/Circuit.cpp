#include "Circuit.hpp"


using namespace std;

Circuit::Circuit(std::string circuit_name, std::vector<Component*> circuit_vec) : circuit_name{circuit_name}, circuit_vec{circuit_vec} {}


void Circuit::simulate_circuit() {
    cout << "In circuit object simulate" << endl;
}

