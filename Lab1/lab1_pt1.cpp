#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

//TODO: complementary work needed, 7-1: Initialize variables using
//braces when possible
//DONE

//TODO: complementary work needed, you are supposed to take an integer
//directly from the input stream on the first task.
//DONE

//TODO: complementary work needed, 8-8: Use manipulators such as
//setfill and setw from the library iomanip when wanting to output
//many characters such as "......".

//TODO: complementary work needed, 5-1: choose names to clearly
//indicate you codes intention.
//DONE

using namespace std;

/*
References: 
https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
Getline was getting 'Enter' (newline) from previous prompt, 
fix is to ignore output between character input and line input
*/


int main() {
    int integer{};
    float floating_pt{};
    char character{};
    string string_var{};

    cout << "Enter one integer: ";
    cin >> integer;
    cout << "You entered the number: " << integer << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter four integers: ";
    cin >> integer;
    cout << "You entered the numbers: " << integer << " ";
    cin >> integer;
    cout << integer << " ";
    cin >> integer;
    cout << integer << " ";
    cin >> integer;
    cout << integer;
    cout << endl << endl;;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter one integer and one real number: ";
    cin >> integer;
    cin >> floating_pt;
    cout << setprecision(4);
    cout << "The real is: \t\t" << floating_pt << endl;
    cout << "The integer is: \t" << integer << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter one real and one integer number: ";
    cin >> floating_pt;
    cin >> integer;
    cout << setprecision(8);
    cout << "The real is:  ......" << floating_pt << endl;
    cout << "The integer is:  ...." << integer << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter a character: ";
    cin >> character;
    cout << "You entered: " << character << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter a word: ";
    cin >> string_var;
    cout << "The word '" << string_var << "' has " << string_var.length() << " character(s)." << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter an integer and a word: ";
    cin >> integer >> string_var;
    cout << "You entered '" << integer << "' and '" << string_var << "'.\n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter a character and a word: ";
    cin >> character >> string_var;
    cout << "You entered the string \"" << string_var << "\" and the character '" << character << "'." << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter a word and a real number: ";
    cin >> string_var >> floating_pt;
    cout << setprecision(5);
    cout << "You entered \"" << string_var << "\" and \"" << floating_pt << "\".\n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter a text-line: ";
    getline(cin, string_var);
    cout << "You entered: \"" << string_var << "\""<< endl << endl;


    cout << "Enter a second line of text: ";
    getline(cin, string_var);
    cout << "You entered: '" << string_var << "\"\n"<< endl;

    cout << "Enter three words: ";
    cin >> string_var;
    cout << "You entered: '" << string_var << " ";
    cin >> string_var;
    cout << string_var << " ";
    cin >> string_var;
    cout << string_var << "'" << endl;

    return 0;
}
