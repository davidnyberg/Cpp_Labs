#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    //store cmd line args 
    //vector<string> args {argv, argv + argc};

    //1 because ./a.out is stored in argv
    if (argc == 1) {
        cerr << "Error: No arguments given." << endl;
        cout << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }

    //want to std::map every word in the file, remove extra junk chars from words.

}