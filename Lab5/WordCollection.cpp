#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
#include <iterator>
using namespace std;

void print_results(string& arg, map<string, int>& container) {
    if (arg == "-a") {
        for_each(container.begin(), container.end(), [](auto pair) { cout << pair.first << " " << pair.second << "\n"; });
    }

    if (arg == "-f") {
        //Source: https://stackoverflow.com/questions/27721578/map-sorting-in-c-by-the-frequencies
        vector<pair<string,int>> values(container.begin(),container.end());
        auto cmp = [](const pair<string,int>& l, pair<string,int>& r) { return l.second > r.second;};
        sort(values.begin(),values.end(),cmp);
        
        //find longest word
        //this needs to be fixed
        //auto max{*max_element(container.begin(), container.end())};

        for_each(values.begin(), values.end(), [](auto pair) { cout << setw(10) << pair.first << " " << pair.second << "\n"; });
    }
}

//prints in original order, with N as formater
void print_o_result(vector<string>& vec, int& n){
    int line_len{0};
    for_each(vec.begin(), vec.end(), [](auto& word){
        cout << word << "\n";
    });
}

bool is_lead_junk(char& c){
    return c == '(' || c == '\'' || c == '\"';
}

bool is_trail_junk(char& c){
    return c == '!' || c == '?' || c == ',' || c == '.' || c == ':' || c == '\"' || c == '\'' || c == ')';
}

int main(int argc, char* argv[]) {

    //store cmd line args 
    vector<string> args {argv, argv + argc};
    int N{0};
    string argument{};
    
    if (argc == 1) {
        cerr << "Error: No arguments given." << endl;
        cout << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }
    else if (argc == 2) {
        cerr << "Error: Second argument missing or invalid." << endl;
        cout << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }
    else if (argc == 3) {
        argument = {args[2]};
        //cout << "Gave arg " << argument << endl;
    } 
    else if (argc == 4) {
        argument = {args[2]};
        //cout << "Gave arg " << argument << endl;

        try {
            N = {stoi(args[3])};
        } catch(invalid_argument& error) {
            cerr << "Error: invalid_argument at: " << error.what() << endl;
            return 1;
        }
    } 
    else {
        cerr << "Too many arguments" << endl;
        return 1;
    }

    

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
    

    // The default-constructed std::istream_iterator is known as the end-of-stream iterator
    // No input calls default constructor -> end of stream. 
    istream_iterator<string> file_stream{file}, end;
    vector<string> raw_words{file_stream, end};


    vector<string> cleaned_words{};
    vector<string> validated_words{};

    //std::transform applies the given function to a range and stores the result in another range, beginning at d_first.
    // first "range"(container) raw words, store results after operations in cleaned words. 
    //clean words
    transform(raw_words.begin(), raw_words.end(), back_inserter(cleaned_words), [] (string& temp_word) -> string {
        //remove leading junk

        //temp_word.erase(0, temp_word.find_first_not_of("\'\"("));

        //give erase index of where any char except the 'junk' is
        auto it = find_if(temp_word.begin(), temp_word.end(), [](auto c) { 
            return is_lead_junk(c);});
        if (it != temp_word.end()) {
            temp_word.erase(temp_word.begin(), it);
        }

        //remove trailing junk, erase does not support reverse iterators, .base fixes this
        //Source: https://stackoverflow.com/questions/1830158/how-to-call-erase-with-a-reverse-iterator

        auto rit = find_if(temp_word.rbegin(), temp_word.rend(), [](auto c){ return is_trail_junk(c);});

        if (rit != temp_word.rend()){
            //cout << *rit << endl;
            temp_word.erase((rit).base() - 1, temp_word.end());
        }

        //source: http://www.cplusplus.com/forum/general/49936/
        if(temp_word.substr(temp_word.length() - 2) == "\'s") {
            temp_word.erase(temp_word.length() - 2); //erase from this point 
        }

        return temp_word;}
    );


    //remove nonvalid words, empty string will be erased at end together with all words < 3. 
    transform(cleaned_words.begin(), cleaned_words.end(), back_inserter(validated_words), [] (auto temp_word) -> string {
        
        //works by if '--' is not found, it will erase nothing
        auto dash_it = find_if(temp_word.begin(), temp_word.end(), [temp_word](auto& c){ return (temp_word.find("--") != string::npos); });
        if (dash_it != temp_word.end()) {
            temp_word.erase(temp_word.begin(), temp_word.end());
        }
        
        //if anything other than alphabet and '-' is found, remove word
        auto it = find_if(temp_word.begin(), temp_word.end(), [](auto& c){ return (!isalpha(c) && c != '-');} );
        if(it != temp_word.end()) {
            temp_word.erase(temp_word.begin(), temp_word.end());
        }

        //all valid words are lowercased
        transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);

        return temp_word;}
    );

    
    //remove any leftover words that are less than 3 chars
    validated_words.erase(remove_if(validated_words.begin(), validated_words.end(), [](auto& word){
        return word.length() < 3; }), validated_words.end());

/*
    cout << "validated words: "; 
    for (auto i : validated_words) {
        cout << i << " ";
    }
    cout << '\n';
*/
    //create a map of the validated words
    map<string, int> word_list{};

    for_each(validated_words.begin(), validated_words.end(), [&word_list](auto& word){ word_list[word]++; });

    if (argument == "-o") {
        print_o_result(validated_words, N);
    }
    print_results(argument, word_list);
    
}