#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


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

    ifstream file{file_name};
    
    /*
    istream_iterator<string> file_stream{file};
    istream_iterator<string> end_of_stream;
    vector<string> potential_words{file_stream, end_of_stream};
    */


    string word{};
    while(file >> word) {
        word_list[word]++;
    }

    vector<string> cleaned_words{};
    

    //some nested lambda functions
    auto strip_junk = [] (auto& pair) -> string {
        //we cannot edit the key of a map, we need to save a temporary pair.first value
        string temp_word{pair.first};

        //remove leading junk
        temp_word.erase(remove_if(temp_word.begin(), temp_word.begin() + 1, [](char x){
            return x == '(' || x == '\'' || x == '\"'; }
                                ), temp_word.begin() + 1);

        //remove trailing junk
        temp_word.erase(remove_if(temp_word.end()-1, temp_word.end(), [](char x){
            return x == '!' || x == '?' || x == ';' || x == ',' || x == ':' || x == '.' || x == '\"' || x == '\'' || x == ')'; }
                                ), temp_word.end());

        return temp_word;
    };
    
    transform(word_list.begin(), word_list.end(), back_inserter(cleaned_words), strip_junk);
    
    
    for (auto word : cleaned_words) {
        cout << word << " " << endl;
    }
    
    cout << endl;
}