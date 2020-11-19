#include <vector>
#include <string>
#include "Component.hpp"
//A circuit should hold a vector of components



class Circuit{
public:
    Circuit(std::string circuit_name, std::vector<Component*> circuit_vec);
    void simulate_circuit();
private:
    std::string circuit_name{""};
    std::vector<Component*> circuit_vec;

    //circuit maybe store all the command line inputs, and then use them in the simulation
};