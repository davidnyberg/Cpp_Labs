#include "Component.h"
#include <vector>

using namespace std;


void simulate(vector<Component*>& circuit) {
    for (auto element : circuit) {
        element->simulate();
    }
}

int main(int argc, char* argv[]) {

int iterations{0};
int n_outputs{0};
double time_step{0};
double voltage{0};

//store cmd line arguments into a vector of strings intstead of c-strings
vector<string> args {argv, argv + argc};
if (args.size() < 5){
    cerr << "Error: Enter number of iterations, number of lines to print, time step, battery voltage." << endl;
    return 1;
}
iterations = stoi(args[1]);
n_outputs = stoi(args[2]);
time_step = stod(args[3]);
voltage = stod(args[4]);
cout << iterations << " " << n_outputs << " " << time_step << " " << voltage << endl;


Connection P, N, r124;
vector<Component*> circuit;

//circuit.push_back(new Battery("Bat", 24.00, P, N));
//circuit.push_back(new Resistor("R1",  6.00, P, r124));

//simulate(circuit);

}