#include <iostream>

using namespace std;

//TODO: Complementary work needed, 8-8: In this lab you are supposed
//to use manipulators from the library iomanip when you want to output
//many characters.

//TODO: Complementary work needed, 1-15: Use cerr for error output
//DONE

//TODO: Complementary work needed, 7-1: Initialize variables using
//braces when possible
//DONE

//TODO: Complementary work needed, 8-8: Your last price should not be
//able to be lower than the first price

//TODO: Complementary work needed, formating should be the same as the
//one in the lab instructions. Hint: Use setfill, setw, fixed and
//setprecision. When you do this, make sure not to repeat sticky
//manipulators. Looping sticky manipulators are also considered
//repeating them.

int main() {
    float first_price{};
    float last_price{};
    float stride{};
    float tax_percent{};

    cout << "INPUT PART\n==========\n"; 
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

    //Checks the inputs for SEK is positive
    while(last_price < 0) {
        cerr << "ERROR: Price (SEK) must be at least 0" << endl;
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
    */
    cout << "TAX TABLE\n==========\n"; 
    cout << "Price\tTax\tPrice With Tax\n-----------------------------" << endl;
    for(;first_price <= last_price; first_price += stride) {
        float tax_amount = {tax_percent/100 * first_price};
        float price_w_tax = {tax_amount + first_price};
        cout << first_price << "\t"<< tax_amount << "\t" << price_w_tax <<endl;
    }
}
