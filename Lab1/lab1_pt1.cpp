#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int i;
    double d;
    float f;
    char c;
    string s;

    cout << "Enter one integer: ";
    cin >> i;
    cout << "You entered the number: " << i << endl << endl;

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
    
    cout << "Enter one integer and one real number: ";
    cin >> i;
    cin >> f;
    cout << setprecision(4);
    cout << "The real is: \t\t" << f << endl;
    cout << "The integer is: \t" << i << endl << endl;

    cout << "Enter one real and one integer number: ";
    cin >> f;
    cin >> i;
    cout << setprecision(4);
    cout << "The real is:  ......" << f << endl;
    cout << "The integer is:  ...." << i << endl << endl;

    cout << "Enter a character: ";
    cin >> c;
    cout << "You entered: " << c << endl << endl;

    cout << "Enter a word: ";
    cin >> s;
    cout << "The word '" << s << "' has " << s.length() << " character(s)." << endl << endl;

    cout << "Enter an integer and a word: ";
    cin >> i >> s;
    cout << "You entered '" << i << "' and '" << s << "'.\n" << endl;

    cout << "Enter a character and a word: ";
    cin >> c >> s;
    cout << "You entered the string \"" << s << "\" and the character '" << c << "'." << endl << endl;

    cout << "Enter a word and a real number: ";
    cin >> s >> f;
    cout << setprecision(3);
    cout << "You entered \"" << s << "\" and \"" << f << "\".\n" << endl;

    /*
    https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
    https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
    Getline was getting 'Enter' (newline) from previous prompt, 
    fix is to ignore output between character input and line input
    */

    //clear buffer, aka ignore one newline char in the buffer
    cin.ignore(1, '\n');
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
