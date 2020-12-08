#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <iterator>
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


    cout << "Opening: " << file_name << endl;

    ifstream file{file_name};
    
    
    istream_iterator<string> file_stream{file}, end;
    vector<string> raw_words{file_stream, end};


    vector<string> cleaned_words{};
    vector<string> validated_words{};
    
    //clean words
    transform(raw_words.begin(), raw_words.end(), back_inserter(cleaned_words), [] (auto& temp_word) -> string {
        //remove leading junk
        temp_word.erase(temp_word.begin(), find_if(temp_word.begin(), temp_word.end(), [](auto c) { return isalpha(c);}));

        //remove trailing junk, erase does not support reverse iterators, .base fixes this
        auto rit = find_if(temp_word.rbegin(), temp_word.rend(), [](auto c){ return isalpha(c);});
        temp_word.erase((rit).base(), temp_word.end());

        //source: http://www.cplusplus.com/forum/general/49936/
        if(temp_word.substr(temp_word.length() - 2) == "\'s") {
            temp_word.erase(temp_word.length() - 2);
        }



        return temp_word;}
    );
    
    //validate words
    transform(cleaned_words.begin(), cleaned_words.end(), back_inserter(validated_words), [] (auto temp_word) -> string {

        temp_word.erase(remove_if(temp_word.begin(), temp_word.end(), [temp_word](auto& c){ return (temp_word.find("--") != string::npos); }), temp_word.end());
        
        auto it = find_if(temp_word.begin(), temp_word.end(), [](auto& c){ return (!isalpha(c) && c != '-');});
        if(it != temp_word.end()) {
            temp_word.erase(temp_word.begin(), temp_word.end());
        }

        return temp_word;}
    );

   validated_words.erase(remove_if(validated_words.begin(), validated_words.end(), [](auto& word){
        return word.length() < 3; }), validated_words.end());


    //now we have all the validated words in a vector

    for (auto word : validated_words) {
        cout << word << " " << endl;
    }
    
}