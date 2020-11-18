#include "Battery.hpp"
#include "Capacitor.hpp"
#include "Resistor.hpp"
#include "Component.hpp"
#include "Circuit.hpp"

#include <vector>
#include <iomanip>


using namespace std;


void simulate(vector<Component*>& circuit, int& iterations, int& n_outputs, float& time_step) {
    //print all the element names and setup the output table
    for (auto element : circuit) {
        cout << element->get_name() << "\t\t";
    }
    cout << endl;
    cout << fixed;
    cout << setprecision(2);

    for(int i{0}; i < iterations; ++i) {
        for (auto element : circuit) {
            element->set_connection_values(time_step);
            if (i %  (iterations / n_outputs) == 0) //print only n_outputs times  
                cout << element->get_voltage() << " " << element->get_current() << "\t";
        }
    if (i %  (iterations / n_outputs) == 0)
        cout << endl;
    }
}

void deallocate_components(vector<Component*>& circuit) {
    for (auto element : circuit) {
        delete element;
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
        //cout << iterations << " " << n_outputs << " " << time_step << " " << voltage << endl;
    }

    Connection P, N, R1, R2, R4, R124, R23;
    vector<Component*> circuit;
    circuit.push_back(new Battery("Bat", voltage, P, N));
    circuit.push_back(new Resistor("R1",  6.00, P, R124));
    circuit.push_back(new Resistor("R2", 4.0, R124, R23));
    circuit.push_back(new Resistor("R3",  8.0, R23, N));
    circuit.push_back(new Resistor("R4",  12.0, R124, N));
    //circuit.push_back(new Capacitor("Cap1", 2.0, P, N));
    simulate(circuit, iterations, n_outputs, time_step);
    deallocate_components(circuit);

    //Circuit cir{"my_cir", circuit};
    //cir.simulate_circuit();
}