#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

/*
References: 
https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
Getline was getting 'Enter' (newline) from previous prompt, 
fix is to ignore output between character input and line input
*/


int main() {
    int i;
    double d;
    float f;
    char c;
    string s;

    cout << "Enter one integer: ";
    getline(cin, s);
    stringstream(s) >> i;
    cout << "You entered the number: " << i << endl << endl;

    //previous solution was to use getline, but could return strings and extra ints instead of just ints
    cout << "Enter four integers: ";
    cin >> i;
    cout << "You entered the numbers: " << i << " ";
    cin >> i;
    cout << i << " ";
    cin >> i;
    cout << i << " ";
    cin >> i;
    cout << i;
    cout << endl << endl;;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter one integer and one real number: ";
    cin >> i;
    cin >> f;
    cout << setprecision(4);
    cout << "The real is: \t\t" << f << endl;
    cout << "The integer is: \t" << i << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter one real and one integer number: ";
    cin >> f;
    cin >> i;
    cout << setprecision(8);
    cout << "The real is:  ......" << f << endl;
    cout << "The integer is:  ...." << i << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter a character: ";
    cin >> c;
    cout << "You entered: " << c << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter a word: ";
    cin >> s;
    cout << "The word '" << s << "' has " << s.length() << " character(s)." << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter an integer and a word: ";
    cin >> i >> s;
    cout << "You entered '" << i << "' and '" << s << "'.\n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter a character and a word: ";
    cin >> c >> s;
    cout << "You entered the string \"" << s << "\" and the character '" << c << "'." << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Enter a word and a real number: ";
    cin >> s >> f;
    cout << setprecision(5);
    cout << "You entered \"" << s << "\" and \"" << f << "\".\n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter a text-line: ";
    getline(cin, s);
    cout << "You entered: \"" << s << "\""<< endl << endl;


    cout << "Enter a second line of text: ";
    getline(cin, s);
    cout << "You entered: '" << s << "\"\n"<< endl;

    cout << "Enter three words: ";
    cin >> s;
    cout << "You entered: '" << s << " ";
    cin >> s;
    cout << s << " ";
    cin >> s;
    cout << s << "'" << endl;

    return 0;
}
