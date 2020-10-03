#include <iostream>
#include <iomanip>
using namespace std;

//TODO: Complementary work needed, 8-8: In this lab you are supposed
//to use manipulators from the library iomanip when you want to output
//many characters.
//DONE

//TODO: Complementary work needed, 1-15: Use cerr for error output
//DONE

//TODO: Complementary work needed, 7-1: Initialize variables using
//braces when possible
//DONE

//TODO: Complementary work needed, 8-8: Your last price should not be
//able to be lower than the first price
//DONE

//TODO: Complementary work needed, formating should be the same as the
//one in the lab instructions. Hint: Use setfill, setw, fixed and
//setprecision. When you do this, make sure not to repeat sticky
//manipulators. Looping sticky manipulators are also considered
//repeating them.
//DONE

int main() {
    float first_price{0.0};
    float last_price{0.0};
    float stride{0.0};
    float tax_percent{0.0};

    cout << "INPUT PART\n"; 
    cout << setfill('=') << setw(10) << "=" << endl;
    cout << "Enter first price: ";
    cin >> first_price;

    //Checks the inputs for SEK is positive
    while(first_price < 0) {
        cerr << "ERROR: Price (SEK) must be at least 0" << endl;
        cout << "Enter first price: ";
        cin >> first_price;
    }

    cout << "Enter last price: ";
    cin >> last_price;

    //Checks the inputs for SEK is positive and greater than first price
    while(last_price < 0 && last_price > first_price) {
        cerr << "ERROR: Price (SEK) must be at least 0 and greater than first price." << endl;
        cout << "Enter last price: ";
        cin >> last_price;
    }

    cout << "Enter stride: ";
    cin >> stride;
    
    //Checks that is greater than 0.01
    while(stride <=  0.01) {
        cerr << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Enter stride: ";
        cin >> stride;
    }

    cout << "Enter tax percent: ";
    cin >> tax_percent;
    //Checks that tax percent is greater than zero
    while(tax_percent < 0) {
        cerr << "ERROR: Tax rate must be greater than 0." << endl;
        cout << "Enter tax percent: ";
        cin >> tax_percent;
    }


    /*
    Print tax table
    Fixed output is now exact same as exmple in lab assignment
    */
    cout << "TAX TABLE\n"; 
    cout << setfill('=') << setw(9) << "=" << endl;
    cout << "\tPrice\t\tTax\tPrice With Tax\n";
    cout << setfill('-') << setw(46) << "-" << endl;

    cout << fixed;
    cout << setprecision(2);
    for(;first_price <= last_price; first_price += stride) {
        float tax_amount = {tax_percent/100 * first_price};
        float price_w_tax = {tax_amount + first_price};
        
        cout << "\t" << first_price << "\t\t"<< tax_amount << "\t\t" << price_w_tax <<endl;
    }
}
