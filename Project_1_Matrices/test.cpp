#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "rational.h"

using namespace std;

int main() {

    // constructors
    cout << "Testing Constructors" << endl;
    RationalNumber first, second(1,2), third;
    // getters and setters
    cout << "Testing Getters" << endl;

    cout << "get numerator:\t\t" << first.get_num() << "\t" << second.get_num() << endl;
    cout << "get denominator:\t" << first.get_den() << "\t" << second.get_den() << endl;
    cout << "first:\t" << first.get_num() << "/" << first.get_den() << endl;
    cout << "second:\t" << second.get_num() << "/" << second.get_den() << endl;
    
    cout << "Testing Setters" << endl;

    cout << "set numerator:\t\t" << "first: " << 1 << "\t" << "second: " << 2 << endl;
    cout << "set denominator:\t" << "first: " << 3 << "\t" << "second: " << 5 << endl;
    
    first.set_num(1);
    second.set_num(2);
    first.set_den(3);
    second.set_den(5);

    cout << "first:\t" << first.get_num() << "/" << first.get_den() << endl;
    cout << "second:\t" << second.get_num() << "/" << second.get_den() << endl;
    
    cout << "set the denominator of second to 0 (Should not work):\t" << endl;
    second.set_den(0);
    cout << "second:\t" << second.get_num() << "/" << second.get_den() << endl;


    // print methods
    cout << "Testing Print Functions" << endl;
    
    // reducing method

    cout << "Testing numerator of 0" << endl;
    first.set_num(0);
    first.set_den(3);
    cout << "Should be 0:\t" << first << endl;
    first.set_num(0);
    first.set_den(-3);
    cout << "Should be 0:\t" << first << endl;

    cout << "Testing negative denominators" << endl;
    first.set_num(1);
    first.set_den(-3);
    cout << "Should be -1/3:\t" << first << endl;
    first.set_num(-1);
    first.set_den(-3);
    cout << "Should be 1/3:\t" << first << endl;

    // reset first to 0/1
    first.set_num(0);

    first.set_num(3);
    first.set_den(-3);
    cout << "Should be -1:\t" << first << endl;
    first.set_num(-3);
    first.set_den(-3);
    cout << "Should be 1:\t" << first << endl;

    // reset first to 0/1
    first.set_num(0);

    first.set_num(3);
    first.set_den(33);
    cout << "Should be 1/11:\t" << first << endl;
    first.set_num(9);
    first.set_den(99);
    cout << "Should be 1/11:\t" << first << endl;
    first.set_num(-3);
    first.set_den(33);
    cout << "Should be -1/11:\t" << first << endl;
    first.set_num(9);
    first.set_den(-99);
    cout << "Should be -1/11:\t" << first << endl;

    
    
    // overloaded operators
    cout << "Testing Operators" << endl;

    // multiplication
    first.set_num(1);
    first.set_den(4);
    
    second.set_num(2);
    second.set_den(3);

    third = first * second;

    cout << first << " * " << second << " = " << third << endl;

    // division
    first.set_num(1);
    first.set_den(21);
    
    second.set_num(3);
    second.set_den(7);

    third = first / second;

    cout << first << " / " << second << " = " << third << endl;

    // addition 
    first.set_num(2);
    first.set_den(3);
    
    second.set_num(1);
    second.set_den(3);

    third = first + second;

    cout << first << " + " << second << " = " << third << endl;

    // subtraction
    first.set_num(2);
    first.set_den(3);
    
    second.set_num(1);
    second.set_den(3);

    third = first - second;

    cout << first << " - " << second << " = " << third << endl;

    // stream operators

    ifstream ins("in.dat");

    ins >> first >> second;

    cout << "first:\t" << first << endl;

    cout << "second:\t" << second << endl;

 


    
    return 0;
}