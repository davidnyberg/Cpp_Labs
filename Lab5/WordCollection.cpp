#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;



void validate(string word) {
    for (auto it = word.begin(); it != word.end(); ++it) {
        cout << *it << endl;
    }
}

int main(int argc, char* argv[]) {

    //store cmd line args 
    vector<string> args {argv, argv + argc};

    /*
    if (argc == 1) {
        cerr << "Error: No arguments given." << endl;
        cout << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }
    */
    string file_name{};
    try {
        file_name = {args[1]};
    }
    catch(invalid_argument& error) {
        cerr << "Error: invalid_argument at: " << error.what() << endl;
        return 1;
    }


    map<string, int> word_list;

    cout << "Opening: " << file_name << endl;

    ifstream file;
    file.open(file_name);
    string word;
    while(file >> word) {
        word_list[word] += 1;
    }

    for (auto& w: word_list) {
        //cout << w.first << ":" << w.second << ' ';
        validate(w.first);
    }
    cout << endl;
}