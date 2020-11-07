#include "Component.h"
#include <vector>

using namespace std;

void simulate(vector<Component*> circuit, iterations, n_outputs, dt) {
    for (auto element : circuit) {
        element->simulate;
    }
}
int main() {

Connection P, N, r124;
vector<Component*> circuit;

circuit.push_back(new Battery("Bat", 24.00, P, N));
circuit.push_back(new Resistor("R1",  6.00, P, r124);

}