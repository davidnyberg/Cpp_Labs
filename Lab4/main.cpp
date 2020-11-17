#include "Battery.hpp"
#include "Capacitor.hpp"
#include "Resistor.hpp"
#include "Component.hpp"
#include "Circuit.hpp"

#include <vector>

using namespace std;


void simulate(vector<Component*>& circuit, int& iterations, int& n_outputs, float& time_step, float& voltage) {
    for (auto element : circuit) {
        element->simulate();
    }
}

int main(int argc, char* argv[]) {

    int iterations{0};
    int n_outputs{0};
    float time_step{0};
    float voltage{0};

    //store cmd line arguments into a vector of strings intstead of c-strings
    vector<string> args {argv, argv + argc};

    if (args.size() != 5){
        cerr << "Error: Provide number of iterations(int), number of lines to print(int), time step(float), battery voltage(float)." << endl;
        return 1;
    } else {
        try{
            iterations = {stoi(args[1])};
            n_outputs = {stoi(args[2])};
            time_step = {stof(args[3])};
            voltage = {stof(args[4])};
        } catch(invalid_argument& error) {
            cerr << "Error: invalid_argument at: " << error.what() << endl;
            cerr << "Error: Provide number of iterations(int), number of lines to print(int), time step(float), battery voltage(float)." << endl;
            return 1;
        }
        cout << iterations << " " << n_outputs << " " << time_step << " " << voltage << endl;
    }

    Connection P, N, r124;
    vector<Component*> circuit;
    circuit.push_back(new Battery("Bat", 24.00, P, N));
    circuit.push_back(new Resistor("R1",  6.00, P, r124));
    circuit.push_back(new Capacitor("Cap1", 2.0, P, N));

    //testing
    Battery bat("Bat", 24.00, P, N);
    Resistor res("R", 6.00, P, N);
    Capacitor cap("Cap", 2.0, P, N);
    bat.set_connection_values();
    bat.get_voltage();
    res.set_connection_values(time_step);
    res.get_voltage();
    cap.set_connection_values(time_step);
    cap.get_voltage();

    Circuit cir{"my_cir", circuit};
    cir.simulate_circuit();
}