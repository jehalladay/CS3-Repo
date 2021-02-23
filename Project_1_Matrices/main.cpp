#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "rational.h"

using namespace std;

int main() {
    ofstream out("out.dat");

    // constructors
    out << "Testing Constructors" << endl;
    RationalNumber first, second(1,2), third;
    // getters and setters
    out << "Testing Getters" << endl;

    out << "get numerator:\t\t" << first.get_num() << "\t" << second.get_num() << endl;
    out << "get denominator:\t" << first.get_den() << "\t" << second.get_den() << endl;
    out << "first:\t" << first.get_num() << "/" << first.get_den() << endl;
    out << "second:\t" << second.get_num() << "/" << second.get_den() << endl;
    
    out << "Testing Setters" << endl;

    out << "set numerator:\t\t" << "first: " << 1 << "\t" << "second: " << 2 << endl;
    out << "set denominator:\t" << "first: " << 3 << "\t" << "second: " << 5 << endl;
    
    first.set_num(1);
    second.set_num(2);
    first.set_den(3);
    second.set_den(5);

    out << "first:\t" << first.get_num() << "/" << first.get_den() << endl;
    out << "second:\t" << second.get_num() << "/" << second.get_den() << endl;
    
    out << "set the denominator of second to 0 (Should not work):\t" << endl;
    second.set_den(0);
    out << "second:\t" << second.get_num() << "/" << second.get_den() << endl;


    // print methods
    out << "Testing Print Functions" << endl;
    first.print_to_file(out);
    out << endl;
    // reducing method

    out << "Testing numerator of 0" << endl;
    first.set_num(0);
    first.set_den(3);
    out << "Should be 0:\t" << first << endl;
    first.set_num(0);
    first.set_den(-3);
    out << "Should be 0:\t" << first << endl;
    out << endl;

    out << "Testing negative denominators" << endl;
    first.set_num(1);
    first.set_den(-3);
    out << "Should be -1/3:\t" << first << endl;
    first.set_num(-1);
    first.set_den(-3);
    out << "Should be 1/3:\t" << first << endl;

    // reset first to 0/1
    first.set_num(0);

    first.set_num(3);
    first.set_den(-3);
    out << "Should be -1:\t" << first << endl;
    first.set_num(-3);
    first.set_den(-3);
    out << "Should be 1:\t" << first << endl;

    // reset first to 0/1
    first.set_num(0);

    first.set_num(3);
    first.set_den(33);
    out << "Should be 1/11:\t" << first << endl;
    first.set_num(9);
    first.set_den(99);
    out << "Should be 1/11:\t" << first << endl;
    first.set_num(-3);
    first.set_den(33);
    out << "Should be -1/11:\t" << first << endl;
    first.set_num(9);
    first.set_den(-99);
    out << "Should be -1/11:\t" << first << endl;
    out << endl;

    
    
    // overloaded operators
    out << "Testing Operators" << endl;
    out << endl;

    out << "Testing Multiplication" << endl;

    // multiplication
    first.set_num(1);
    first.set_den(4);
    
    second.set_num(2);
    second.set_den(3);

    third = first * second;

    out << first << " * " << second << " = " << third << endl;
    out << endl;

    out << "Testing Division" << endl;

    // division
    first.set_num(1);
    first.set_den(21);
    
    second.set_num(3);
    second.set_den(7);

    third = first / second;

    out << first << " / " << second << " = " << third << endl;
    out << endl;

    out << "Testing Addition" << endl;

    // addition 
    first.set_num(2);
    first.set_den(3);
    
    second.set_num(1);
    second.set_den(3);

    third = first + second;

    out << first << " + " << second << " = " << third << endl;
    out << endl;

    out << "Testing Subtraction" << endl;

    // subtraction
    first.set_num(2);
    first.set_den(3);
    
    second.set_num(1);
    second.set_den(3);

    third = first - second;

    out << first << " - " << second << " = " << third << endl;

    // stream operators
    out << "Testing stream operators" << endl;
    out << endl;

    ifstream ins("in.dat");

    ins >> first >> second;

    out << "first:\t" << first << endl;
    // first.print_to_file()

    out << "second:\t" << second << endl;
    // second.print_to_file()

    ins.close();
    out << endl;

    // Test the Rational Number Implementation with given data

    ifstream inf("in.dat");

    while(!inf.eof()) {
        inf >> first >> second;
        out << "first = " << first << "\tsecond = " << second << endl;
        third = first + second;
        out << first << " + " << second << " = " << third << endl;
        third = first - second;
        out << first << " - " << second << " = " << third << endl;
        third = first * second;
        out << first << " * " << second << " = " << third << endl;
        third = first / second;
        out << first << " / " << second << " = " << third << endl;
        out << endl;
    }

    
    return 0;
}