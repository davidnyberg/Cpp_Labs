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


    //map<string, int> word_list;

    cout << "Opening: " << file_name << endl;

    ifstream file{file_name};
    
    /*
    istream_iterator<string> file_stream{file};
    istream_iterator<string> end_of_stream;
    vector<string> potential_words{file_stream, end_of_stream};
    */

    vector<string> raw_words;
    string word{};
    while(file >> word) {
        raw_words.push_back(word);
    }

    vector<string> cleaned_words{};
    vector<string> validated_words{};
    
    //clean words
    transform(raw_words.begin(), raw_words.end(), back_inserter(cleaned_words), [] (auto& temp_word) -> string {

        //remove leading junk
        temp_word.erase(temp_word.begin(), find_if(temp_word.begin(), temp_word.end(), [](auto c) { return isalpha(c);}));


        //remove trailing junk, erase does not support reverse iterators, .base fixes this
        auto rit = find_if(temp_word.rbegin(), temp_word.rend(), [](auto c){ return isalpha(c);});
        temp_word.erase((rit).base(), temp_word.end());

        return temp_word;}
    );

    //cleaned_words.erase(find_if(temp_word.end(), temp_word.begin(), [](auto c){ return isalpha(c);}), temp_word.end())
    
    //remove short words >= 3 chars
    cleaned_words.erase(remove_if(cleaned_words.begin(), cleaned_words.end(), [](auto& word){
        return word.length() < 3; }), cleaned_words.end());

        for (auto word : cleaned_words) {
        cout << word << " " << endl;
    }

    //remove word if it contains numbers
    cleaned_words.erase(remove_if(cleaned_words.begin(), cleaned_words.end(), [](auto& word){
        return any_of(word.begin(), word.end(), [](auto x) {
            return !isalpha(x) && x != '-';
        });
    }), cleaned_words.end());

   // transform(cleaned_words.begin(), cleaned_words.end(), back_inserter(validated_words), [] (auto& temp_word) -> string {}

    for (auto word : cleaned_words) {
        cout << word << " " << endl;
    }
    
}